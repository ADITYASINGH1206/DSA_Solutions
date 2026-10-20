/**
 * Problem: Walking Robot Simulation II (2069)
 * Link: https://leetcode.com/problems/walking-robot-simulation-ii/
 * Difficulty: Medium
 */

#include <bits/stdc++.h>
using namespace std;

class Robot {
private:
    int w;
    int h;
    int perimeter;
    int pos;
    bool has_moved;

public:
    Robot(int width, int height) {
        w = width - 1;
        h = height - 1;
        perimeter = 2 * w + 2 * h;
        pos = 0;
        has_moved = false;
    }
    
    void step(int num) {
        has_moved = true;
        pos = (pos + num) % perimeter;
    }
    
    vector<int> getPos() {
        if (pos <= w) {
            return {pos, 0};
        } else if (pos <= w + h) {
            return {w, pos - w};
        } else if (pos <= 2 * w + h) {
            return {2 * w + h - pos, h};
        } else {
            return {0, perimeter - pos};
        }
    }
    
    string getDir() {
        if (pos == 0) {
            return has_moved ? "South" : "East";
        } else if (pos <= w) {
            return "East";
        } else if (pos <= w + h) {
            return "North";
        } else if (pos <= 2 * w + h) {
            return "West";
        } else {
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
