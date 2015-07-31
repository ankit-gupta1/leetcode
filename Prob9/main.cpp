/*
 * main.cpp
 *
 *  Created on: Jul 31, 2015
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
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        bool isPal = true;
        int numDigits = 0;

        int64_t y = x;
        int64_t temp = 1;
        while (y != 0) {
            y = y / 10;
            numDigits++;
            temp = temp * 10;
        }

        int64_t start = 1;
        temp = temp / 10;
        y = x;
        for (int i = 0; i < numDigits / 2; i++) {
            if ((x / start) % 10 != (x / temp) % 10) {
                isPal = false;
                break;
            }

            start *= 10;
            temp /= 10;
        }

        return isPal;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(1000000001);
    return 0;
}
