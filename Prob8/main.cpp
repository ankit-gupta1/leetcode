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
    int myAtoi(string str) {
        int64_t result = 0;
        vector<int> digits;

        int signVal = 1;
        bool inInteger = false;
        bool haveSign = false;

        for (unsigned int i = 0; i < str.length(); i++) {
            if ((str[i] == 43 || str[i] == 45) && !inInteger && !haveSign) {
                inInteger = true;
                haveSign = true;
                signVal = str[i] == 43 ? 1 : -1;
            } else if ((str[i] == 43 || str[i] == 45) && (inInteger || haveSign)) {
                break;
            } else if (str[i] >= 48 && str[i] <= 57) {
                inInteger = true;
                digits.push_back((int)(str[i] - 48));
            } else if (!(str[i] >= 48 && str[i] <= 57) && !(str[i] == 43 || str[i] == 45)) {
                if ((inInteger || haveSign)) {
                    break;
                } else if (str[i] != 32) {
                    break;
                }
            }
        }

        int64_t y = signVal;
        int n = digits.size();

        for (int i = 0; i < n && n > 0; i++) {
            result += y * (int64_t)digits[n - i - 1];
            if (result <= INT_MIN || result >= INT_MAX) {
                result = result <= INT_MIN ? INT_MIN : INT_MAX;
                break;
            }

            y = y * 10;
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("123");
    return 0;
}

