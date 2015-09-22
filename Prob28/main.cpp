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

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int occrIdx = -1;
        int needleLength = needle.length();
        int haystackLength = haystack.length();

        if (haystackLength == 0 && needleLength == 0) {
            occrIdx = 0;
        } else if (haystackLength >= needleLength) {
            for (unsigned int i = 0; i <= haystackLength - needleLength; i++) {
                if (needle == haystack.substr(i, needleLength)) {
                    occrIdx = i;
                    break;
                }
            }
        }

        return occrIdx;
    }
};

int main() {
    return 0;
}

