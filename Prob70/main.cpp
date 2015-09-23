/*
 * main.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: ankit
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <limits.h>
#include <set>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int ways = 0;

        if (n == 1) {
            ways = 1;
        } if (n == 2) {
            ways = 2;
        } else if (n > 2) {
            int waysOneStep = 1;
            int waysTwoStep = 2;

            for (int i = 3; i <= n; i++) {
                ways = waysOneStep + waysTwoStep;
                waysOneStep = waysTwoStep;
                waysTwoStep = ways;
            }
        }

        return ways;
    }
};

int main() {
    return 0;
}


