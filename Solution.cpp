class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        
        unordered_map<char, int> freq;
        unordered_map<char, int> idx;
        vector<char> vowels;
        
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                if (freq.find(s[i]) == freq.end()) {
                    vowels.push_back(s[i]);
                    idx[s[i]] = i;
                }
                freq[s[i]]++;
            }
        }

        sort(vowels.begin(), vowels.end(), [&](char a, char b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b]; 
            }
            return idx[a] < idx[b]; 
        });

        int idxs = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[idxs];
                freq[s[i]]--; 
                if (freq[s[i]] == 0) {
                    idxs++;
                }
            }
        }

        return s;
    }
};

