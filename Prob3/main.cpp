/*
 * main.cpp
 *
 *  Created on: Jun 21, 2015
 *      Author: ankit
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned int length = s.length();
        unsigned int i = 0;
        unsigned int maxLength = 0;
        unsigned int currLength = 0;
        map<char, unsigned int> charMap;

        while (i < length) {
            if (charMap.find(s[i]) == charMap.end()) {
                charMap[s[i]] = i;
                currLength++;
            } else {
                unsigned int lastVisit = charMap[s[i]];

                if (lastVisit + currLength < i) {
                    currLength++;
                } else {
                    currLength = i - lastVisit;
                }

                charMap[s[i]] = i;
            }

            if (maxLength < currLength) {
                maxLength = currLength;
            }

            i++;
        }

        charMap.erase(charMap.begin(), charMap.end());
        return maxLength;

    }
};

int main() {
    string s = "ageeksforgeeksa";
    Solution a;
    cout << a.lengthOfLongestSubstring(s);
    return 0;
}

