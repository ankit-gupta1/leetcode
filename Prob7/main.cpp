/*
 * main.cpp
 *
 *  Created on: Jul 30, 2015
 *      Author: ankit
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int64_t result = 0;

        if (x != 0 && x < INT_MAX && x > INT_MIN) {

            int64_t y = abs(x);
            int n = 0;

            vector<int> digits;

            while (y != 0) {
                digits.push_back(y % 10);
                y = y / 10;
                n++;
            }

            y = 1;
            for (int i = 0; i < n; i++) {
                result += (int64_t) (y * digits[n - i - 1]);
                y = y * 10;

                if (result > INT_MAX) {
                    return 0;
                }
            }
        }

        return x >= 0 ? result : -result;
    }
};

int main() {
    Solution s;
    cout << s.reverse(1534236469);
    return 0;
}

