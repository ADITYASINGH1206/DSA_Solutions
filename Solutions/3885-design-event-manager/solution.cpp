/**
 * Problem: Design Event Manager (3885)
 * Link: https://leetcode.com/problems/design-event-manager/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

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
