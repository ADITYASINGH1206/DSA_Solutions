/**
 * Problem: Calculator with Method Chaining (2726)
 * Link: https://leetcode.com/problems/calculator-with-method-chaining/
 * Difficulty: Easy
 */

#include <bits/stdc++.h>
using namespace std;

class Calculator {
    private x: number;

    constructor(value: number) {
        this.x = value;
    }

    add(value: number): Calculator {
        this.x += value;
        return this;
    }

    subtract(value: number): Calculator {
        this.x -= value;
        return this;
    }

    multiply(value: number): Calculator {
        this.x *= value;
        return this;
    }

    divide(value: number): Calculator {
        if (value === 0) {
            throw new Error('Division by zero is not allowed');
        }
        this.x /= value;
        return this;
    }

    power(value: number): Calculator {
        this.x **= value;
        return this;
    }

    getResult(): number {
        return this.x;
    }
}
