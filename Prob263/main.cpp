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
    bool isUgly(int num) {

        if (num <= 0) {
            return false;
        }

        bool truth = true;
        num = abs(num);

        while (num > 0 && num % 2 == 0) {
            num = num / 2;
        }

        while (num > 0 && num % 3 == 0) {
            num = num / 3;
        }

        while (num > 0 && num % 5 == 0) {
            num = num / 5;
        }

        if (num > 1 || num == INT_MIN) {
            truth = false;
        }

        return truth;
    }
};

int main() {
    Solution s;
    cout << s.isUgly(-1000) << endl;
    return 0;
}
