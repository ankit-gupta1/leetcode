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

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector< bool > temp(s.length(), false);
        vector< vector<bool> > isPal(s.length(), temp);

        unsigned int maxStart = 0;
        unsigned int maxLength = 1;

        unsigned int currStart = 0;
        unsigned int currLength = 1;

        for (unsigned int i = 0; i < s.length(); i++) {
            isPal[i][i] = true;
        }

        for (unsigned int j = 1; j < s.length(); j++) {
            for (unsigned int i = 0; i < j; i++) {
                if (s[j] == s[i]) {
                    if ((j - i > 1)) {
                        if (isPal[i + 1][ j - 1]) {
                            isPal[i][j] = true;
                            currStart = i;
                            currLength = j - i + 1;
                        }
                    } else {
                        isPal[i][j] = true;
                        currStart = i;
                        currLength = 2;
                    }
                }

                if (currLength > maxLength) {
                    maxLength = currLength;
                    maxStart = currStart;
                }
            }
        }

        return s.substr(maxStart, maxLength);
    }
};

int main() {
    return 0;
}
