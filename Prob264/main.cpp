/*
 * main.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: ankit
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <limits.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n);
        int nextUglyNum = 1;
        uglyNums[0] = nextUglyNum;

        int nextMultipleOf2 = uglyNums[0] * 2;
        int nextMultipleOf3 = uglyNums[0] * 3;
        int nextMultipleOf5 = uglyNums[0] * 5;

        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for (int iter = 1; iter < n; iter++) {
            nextUglyNum = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNums[iter] = nextUglyNum;

            if (nextUglyNum == nextMultipleOf2) {
                nextMultipleOf2 = uglyNums[++i2] * 2;
            }
            if (nextUglyNum == nextMultipleOf3) {
                nextMultipleOf3 = uglyNums[++i3] * 3;
            }
            if (nextUglyNum == nextMultipleOf5) {
                nextMultipleOf5 = uglyNums[++i5] * 5;
            }
        }

        return nextUglyNum;
    }
};

int main() {
    Solution s;
    cout << s.nthUglyNumber(10) << endl;
    return 0;
}
