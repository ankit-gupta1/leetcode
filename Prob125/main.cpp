/*
 * main.cpp
 *
 *  Created on: Oct 7, 2015
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
    bool isAlphaNumeric(char a) {
        if ((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
            return true;
        } else {
            return false;
        }
    }

    bool isPalindrome(string s) {
        bool result = true;
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            while (isAlphaNumeric(s[start]) == false && start < end) {
                start++;
            }

            while (isAlphaNumeric(s[end]) == false && start < end) {
                end--;
            }

            if (tolower(s[start++]) != tolower(s[end--])) {
                result = false;
                break;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("aa");
    return 0;
}

