import time
from typing import Dict, Any, List, Optional
try:
    from curl_cffi import requests
    HAS_CURL_CFFI = True
except ImportError:
    import requests  # type: ignore
    HAS_CURL_CFFI = False


class LeetCodeClient:
    """
    LeetCode GraphQL API Client with Cloudflare JA3/TLS fingerprint impersonation.
    Handles querying submissions, problem metadata, solution checking, and article publication.
    """

    def __init__(self, session_cookie: str, csrf_token: str, username: str):
        self.url = "https://leetcode.com/graphql/"
        self.username = username.strip()
        self.csrf_token = csrf_token.strip()
        self.session_cookie = session_cookie.strip()

        # Initialize session with browser TLS fingerprint if curl_cffi is available
        if HAS_CURL_CFFI:
            self.session = requests.Session(impersonate="chrome124")
        else:
            self.session = requests.Session()

        self.session.headers.update({
            "Content-Type": "application/json",
            "Cookie": f"LEETCODE_SESSION={self.session_cookie}; csrftoken={self.csrf_token};",
            "x-csrftoken": self.csrf_token,
            "Origin": "https://leetcode.com",
            "Referer": "https://leetcode.com/",
            "User-Agent": (
                "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) "
                "AppleWebKit/537.36 (KHTML, like Gecko) "
                "Chrome/124.0.0.0 Safari/537.36"
            ),
        })

    def _query(self, query: str, variables: Optional[Dict[str, Any]] = None, referer_slug: str = "") -> Dict[str, Any]:
        """
        Execute a GraphQL query/mutation against LeetCode with error handling.
        """
        if referer_slug:
            self.session.headers["Referer"] = f"https://leetcode.com/problems/{referer_slug}/"
        else:
            self.session.headers["Referer"] = "https://leetcode.com/"

        payload = {
            "query": query,
            "variables": variables or {},
        }

        resp = self.session.post(self.url, json=payload, timeout=30)

        if resp.status_code == 403:
            raise PermissionError(
                "403 Forbidden from LeetCode. Your LEETCODE_SESSION or csrftoken may have expired, "
                "or Cloudflare challenged the request. Please update your tokens in .env."
            )

        resp.raise_for_status()
        res_json = resp.json()

        if "errors" in res_json and res_json["errors"]:
            error_details = res_json["errors"]
            # Detect common rate limit / posting too frequently message
            err_msg = str(error_details)
            if "posting too frequently" in err_msg.lower() or "too many requests" in err_msg.lower():
                raise RuntimeError(f"Rate limited by LeetCode: {err_msg}")
            raise RuntimeError(f"LeetCode GraphQL Error: {err_msg}")

        return res_json.get("data", {})

    def get_recent_ac_submissions(self, limit: int = 20) -> List[Dict[str, Any]]:
        """
        Fetch the user's most recent accepted submissions.
        Returns up to limit items with id, title, titleSlug, timestamp.
        """
        query = """
        query recentAcSubmissions($username: String!, $limit: Int!) {
          recentAcSubmissionList(username: $username, limit: $limit) {
            id
            title
            titleSlug
            timestamp
          }
        }
        """
        data = self._query(query, {"username": self.username, "limit": limit})
        return data.get("recentAcSubmissionList", []) or []

    def get_all_solved_questions(self, limit_per_page: int = 50) -> List[Dict[str, Any]]:
        """
        Paginate through the user's solved question list to enable full historical backfill.
        Queries problemsetQuestionList with filter: { status: "AC" }.
        """
        query = """
        query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
          problemsetQuestionList: questionList(
            categorySlug: $categorySlug
            limit: $limit
            skip: $skip
            filters: $filters
          ) {
            total: totalNum
            questions: data {
              questionId
              questionFrontendId
              title
              titleSlug
              difficulty
              topicTags {
                name
                slug
              }
            }
          }
        }
        """
        questions = []
        skip = 0

        while True:
            variables = {
                "categorySlug": "",
                "skip": skip,
                "limit": limit_per_page,
                "filters": {"status": "AC"},
            }
            data = self._query(query, variables)
            qlist = data.get("problemsetQuestionList", {})
            total = qlist.get("total", 0)
            batch = qlist.get("questions", []) or []

            if not batch:
                break

            questions.extend(batch)
            skip += len(batch)

            if skip >= total or len(batch) < limit_per_page:
                break

            time.sleep(0.5)  # brief anti-rate-limit breather during question list pagination

        return questions

    def get_latest_ac_submission_for_question(self, question_slug: str, preferred_lang: str = "cpp") -> Optional[Dict[str, Any]]:
        """
        Query questionSubmissionList to find the latest Accepted submission ID for a specific question,
        prioritizing C++ (cpp) submissions.
        """
        query = """
        query submissionList($questionSlug: String!, $offset: Int!, $limit: Int!, $status: Int) {
          questionSubmissionList(
            questionSlug: $questionSlug
            offset: $offset
            limit: $limit
            status: $status
          ) {
            submissions {
              id
              titleSlug
              lang
              timestamp
              runtime
              memory
            }
          }
        }
        """
        variables = {
            "questionSlug": question_slug,
            "offset": 0,
            "limit": 15,
            "status": 10,  # 10 = Accepted
        }
        data = self._query(query, variables, referer_slug=question_slug)
        submissions = data.get("questionSubmissionList", {}).get("submissions", []) or []

        if not submissions:
            return None

        # Filter for preferred language (e.g. C++: cpp, c++, clang)
        cpp_targets = ["cpp", "c++", "clang"] if preferred_lang.lower() in ["cpp", "c++"] else [preferred_lang.lower()]
        for sub in submissions:
            if sub.get("lang", "").lower() in cpp_targets:
                return sub

        # Fallback to the latest accepted submission if preferred lang not found
        return submissions[0]

    def get_submission_details(self, submission_id: int) -> Dict[str, Any]:
        """
        Fetch the exact source code, percentiles, runtime, memory, and full question details for a submission.
        """
        query = """
        query submissionDetails($submissionId: Int!) {
          submissionDetails(submissionId: $submissionId) {
            runtime
            runtimePercentile
            memory
            memoryPercentile
            code
            lang {
              name
            }
            question {
              questionId
              questionFrontendId
              title
              titleSlug
              content
              difficulty
              topicTags {
                name
                slug
              }
            }
          }
        }
        """
        data = self._query(query, {"submissionId": int(submission_id)})
        details = data.get("submissionDetails")
        if not details:
            raise ValueError(f"No submission details returned for ID {submission_id}")
        return details

    def get_all_user_solution_articles(self, force_refresh: bool = False) -> Dict[str, Dict[str, Any]]:
        """
        Fetch all community solution articles authored by the user on LeetCode.
        Returns a dict mapping question_slug -> article_dict (containing uuid, title, slug, questionSlug).
        Cached in memory to prevent duplicate publications.
        """
        if hasattr(self, "_user_solution_articles") and self._user_solution_articles is not None and not force_refresh:
            return self._user_solution_articles

        query = """
        query ugcArticleUserSolutionArticles($username: String!, $skip: Int!, $first: Int!) {
          ugcArticleUserSolutionArticles(username: $username, skip: $skip, first: $first) {
            totalNum
            edges {
              node {
                uuid
                title
                slug
                questionSlug
                questionTitle
              }
            }
          }
        }
        """
        articles_by_slug = {}
        skip = 0
        first = 50

        while True:
            try:
                res = self._query(query, {"username": self.username, "skip": skip, "first": first})
                data = res.get("ugcArticleUserSolutionArticles", {})
                edges = data.get("edges", []) or []
                total = data.get("totalNum", 0)

                for e in edges:
                    node = e.get("node")
                    if node and node.get("questionSlug"):
                        articles_by_slug[node["questionSlug"]] = node

                skip += len(edges)
                if not edges or skip >= total:
                    break
                time.sleep(0.3)
            except Exception as e:
                print(f"[WARNING] Failed while paginating user solution articles at skip={skip}: {e}")
                break

        self._user_solution_articles = articles_by_slug
        return self._user_solution_articles

    def has_user_posted_solution(self, question_slug: str) -> bool:
        """
        Check if the user has already published a solution article on LeetCode for this problem.
        """
        articles = self.get_all_user_solution_articles()
        return question_slug in articles

    def get_user_posted_solution(self, question_slug: str) -> Optional[Dict[str, Any]]:
        """
        Return the article details (uuid, slug, title) if user already posted a solution on LeetCode.
        """
        articles = self.get_all_user_solution_articles()
        return articles.get(question_slug)

    def publish_solution(self, question_slug: str, title: str, content: str, tags: List[str]) -> Dict[str, Any]:
        """
        Publish the solution article to LeetCode Community via ugcArticlePublishSolution mutation.
        Enforces tags containing 'c', summary, and valid schema.
        """
        mutation = """
        mutation publishSolution($data: UgcArticlePublishSolutionInput!) {
          ugcArticlePublishSolution(data: $data) {
            article {
              uuid
              title
              slug
            }
          }
        }
        """
        # Ensure 'c' is in tags for C++ solution articles
        tag_list = list(tags)
        if "c" not in tag_list:
            tag_list.insert(0, "c")

        variables = {
            "data": {
                "questionSlug": question_slug,
                "title": title,
                "content": content,
                "tags": tag_list,
                "summary": title[:200],
                "thumbnail": "",
                "isSerialized": False,
            }
        }
        data = self._query(mutation, variables, referer_slug=question_slug)
        result = data.get("ugcArticlePublishSolution", {}).get("article")
        if not result:
            raise RuntimeError(f"Publication succeeded but no article returned: {data}")
        return result
