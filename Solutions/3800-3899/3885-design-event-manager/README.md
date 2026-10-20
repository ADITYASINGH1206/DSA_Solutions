# [3885. Design Event Manager](https://leetcode.com/problems/design-event-manager/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `design`, `heap-priority-queue`, `ordered-set`

---

## Problem Description
You are given an initial list of events, where each event has a unique `eventId` and a `priority`.

Implement the `EventManager` class:

* `EventManager(int[][] events)` Initializes the manager with the given events, where `events[i] = [eventIdi, priority​​​​​​​i]`.
* `void updatePriority(int eventId, int newPriority)` Updates the priority of the **active** event with id `eventId` to `newPriority`.
* `int pollHighest()` Removes and returns the `eventId` of the **active** event with the **highest** priority. If multiple active events have the same priority, return the **smallest** `eventId` among them. If there are no active events, return -1.

An event is called **active** if it has not been removed by `pollHighest()`.

**Example 1:**

**Input:**  
["EventManager", "pollHighest", "updatePriority", "pollHighest", "pollHighest"]  
[[[[5, 7], [2, 7], [9, 4]]], [], [9, 7], [], []]

**Output:**  
[null, 2, null, 5, 9]

**Explanation**

EventManager eventManager = new EventManager([[5,7], [2,7], [9,4]]); // Initializes the manager with three events  
eventManager.pollHighest(); // both events 5 and 2 have priority 7, so return the smaller id 2  
eventManager.updatePriority(9, 7); // event 9 now has priority 7  
eventManager.pollHighest(); // remaining highest priority events are 5 and 9, return 5  
eventManager.pollHighest(); // return 9

**Example 2:**

**Input:**  
["EventManager", "pollHighest", "pollHighest", "pollHighest"]  
[[[[4, 1], [7, 2]]], [], [], []]

**Output:**  
[null, 7, 4, -1]

**Explanation**

EventManager eventManager = new EventManager([[4,1], [7,2]]); // Initializes the manager with two events  
eventManager.pollHighest(); // return 7  
eventManager.pollHighest(); // return 4  
eventManager.pollHighest(); // no events remain, return -1

**Constraints:**

* `1 <= events.length <= 105`
* `events[i] = [eventId, priority]`
* `1 <= eventId <= 109`
* `1 <= priority <= 109`
* All the values of `eventId` in `events` are **unique**.
* `1 <= newPriority <= 109`
* For every call to `updatePriority`, `eventId` refers to an **active** event.
* At most `105` calls in **total** will be made to `updatePriority` and `pollHighest`.

---

## Solution & Editorial
# Intuition
To efficiently manage events by priority while supporting updates and extraction, we need a data structure that maintains elements in a sorted order. Since we need to extract the highest priority (and the smallest ID in case of ties), a `std::set` of pairs is ideal. By storing priorities as negative values, we can leverage the default ascending order of `std::set` to effectively simulate a max-priority queue.

# Approach
1. **Data Structures**: We use a `std::map<int, int> idToPriority` to keep track of the current priority of each active event, and a `std::set<pair<int, int>> activeEvents` to store pairs of `{-priority, eventId}`. The set keeps elements sorted primarily by priority (descending due to negation) and secondarily by `eventId` (ascending).
2. **Initialization**: Iterate through the input `events`, populating both the map and the set.
3. **Update**: To update an event, remove the old `{-oldPriority, eventId}` pair from the set, update the map, and insert the new `{-newPriority, eventId}` pair.
4. **Poll**: Access the first element of the set (the smallest `{-priority, id}`), which corresponds to the highest priority and smallest ID. Remove it from both the set and the map.

### Visual Trace (Example 1)
Initial: `activeEvents = {(-7, 2), (-7, 5), (-4, 9)}`
1. `pollHighest()`: `activeEvents.begin()` is `(-7, 2)`. Return `2`. `activeEvents` becomes `{(-7, 5), (-4, 9)}`.
2. `updatePriority(9, 7)`: Remove `(-4, 9)`, insert `(-7, 9)`. `activeEvents` becomes `{(-7, 5), (-7, 9)}`.
3. `pollHighest()`: `activeEvents.begin()` is `(-7, 5)`. Return `5`. `activeEvents` becomes `{(-7, 9)}`.
4. `pollHighest()`: `activeEvents.begin()` is `(-7, 9)`. Return `9`. `activeEvents` becomes `{}`.

# Complexity
- Time complexity: $$O(\log N)$$ per operation. Both `std::set` insertion/deletion and `std::map` lookups/updates are logarithmic relative to the number of active events $$N$$.
- Space complexity: $$O(N)$$ to store the active events in the map and the set.

# Code
```cpp
class EventManager {
public:
    map<int, int> idToPriority;
    set<pair<int, int>> activeEvents;
    EventManager(vector<vector<int>>& events) {
        for (const auto& event : events) {
            int id = event[0];
            int priority = event[1];
            idToPriority[id] = priority;
            activeEvents.insert({-priority, id});
        }
    }

    void updatePriority(int eventId, int newPriority) {
        if (idToPriority.count(eventId)) {
            int oldPriority = idToPriority[eventId];
            activeEvents.erase({-oldPriority, eventId});
            
            idToPriority[eventId] = newPriority;
            activeEvents.insert({-newPriority, eventId});
        }
    }

    int pollHighest() {
        if (activeEvents.empty()) {
            return -1;
        }

        auto it = activeEvents.begin();
        int eventId = it->second;

        activeEvents.erase(it);
        idToPriority.erase(eventId);

        return eventId;
    }
};
```
