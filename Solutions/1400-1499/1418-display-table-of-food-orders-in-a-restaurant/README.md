# [1418. Display Table of Food Orders in a Restaurant](https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `string`, `sorting`, `ordered-set`

---

## Problem Description
Given the array `orders`, which represents the orders that customers have done in a restaurant. More specifically `orders[i]=[customerNamei,tableNumberi,foodItemi]` where `customerNamei` is the name of the customer, `tableNumberi` is the table customer sit at, and `foodItemi` is the item customer orders.

*Return the restaurant's “**display table**”*. The “**display table**” is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is “Table”, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.

**Example 1:**

```

Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
Explanation:
The displaying table looks like:
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche".
For the table 5: Carla orders "Water" and "Ceviche".
For the table 10: Corina orders "Beef Burrito". 
```

**Example 2:**

```

Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
Explanation: 
For the table 1: Adam and Brianna order "Canadian Waffles".
For the table 12: James, Ratesh and Amadeus order "Fried Chicken".
```

**Example 3:**

```

Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
Output: [["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
```

**Constraints:**

* `1 <= orders.length <= 5 * 10^4`
* `orders[i].length == 3`
* `1 <= customerNamei.length, foodItemi.length <= 20`
* `customerNamei` and `foodItemi` consist of lowercase and uppercase English letters and the space character.
* `tableNumberi`is a valid integer between `1` and `500`.

---

## Solution & Editorial
# Intuition
To construct the display table, we need to aggregate food counts per table and ensure both the table numbers and food items are sorted. A `std::map<int, std::unordered_map<string, int>>` naturally handles the sorting of table numbers while providing efficient lookups for food items, and a `std::set<string>` ensures we have a unique, sorted list of all food items present in the orders.

# Approach
1. **Data Aggregation**: Iterate through the `orders` array. Parse the `tableNumber` as an integer and use it as a key in a `std::map`. Store the counts of each `foodItem` in an `unordered_map` associated with that table. Simultaneously, insert every `foodItem` into a `std::set<string>` to maintain a sorted list of unique items.
2. **Header Construction**: Create the first row of the result by starting with "Table" and appending all items from the `std::set`.
3. **Row Generation**: Iterate through the sorted `map` (the tables). For each table, iterate through the sorted `items` set. If the table ordered the item, retrieve the count; otherwise, append "0".

### Visual Trace (Example 1)
| Step | Table | Items (Set) | Map State |
| :--- | :--- | :--- | :--- |
| Init | - | {} | {} |
| Process | 3 | {Ceviche, Fried Chicken} | {3: {Ceviche: 2, Fried Chicken: 1}} |
| Process | 5 | {Ceviche, Fried Chicken, Water} | {3: {...}, 5: {Water: 1, Ceviche: 1}} |
| Process | 10 | {..., Beef Burrito} | {3: {...}, 5: {...}, 10: {Beef Burrito: 1}} |

# Complexity
- Time complexity: $$O(N \log N + T \cdot F)$$, where $$N$$ is the number of orders, $$T$$ is the number of unique tables, and $$F$$ is the number of unique food items. The $$N \log N$$ accounts for map insertions, and $$T \cdot F$$ accounts for iterating through the map and set to build the output grid.
- Space complexity: $$O(T \cdot F)$$, required to store the aggregated counts in the nested map structure and the final result grid.

# Code
```cpp
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> map;
        set<string> items;

        for (int i = 0, n = orders.size(); i < n; ++i) {
            int table = stoi(orders[i][1]);
            string food = orders[i][2];
            ++map[table][food];
            items.insert(food);
        }

        vector<vector<string>> ans;
        vector<string> header{"Table"};
        header.insert(header.end(), items.begin(), items.end());
        ans.push_back(header);

        for (auto [table, foodCount] : map) {
            vector<string> row{to_string(table)};
            for (string food : items) {
                if(foodCount.count(food)) row.push_back(to_string(foodCount.at(food)));
                else row.push_back("0");
            }
            ans.push_back(row);
        }
        return ans;
    }
};
```
