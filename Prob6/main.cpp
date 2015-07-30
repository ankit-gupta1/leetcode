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
    string convert(string s, int numRows) {
        string result;

        if (numRows == 1) {
            return s;
        }

        for (unsigned int i = 0; i < numRows; i++) {
            unsigned int stepSize0;
            unsigned int stepSize1;

            if (i == 0 || i == numRows - 1) {
                stepSize0 = (2 * (numRows - 1));
                stepSize1 = (2 * (numRows - 1));
            } else {
                stepSize0 = (2 * (numRows - i - 1));
                stepSize1 = (2 * i);
            }

            bool flip = true;
            unsigned int j = i;

            while (j < s.length()) {

                result.append(s, j, 1);

                if (flip) {
                    j += stepSize0;
                    flip = false;
                } else {
                    j += stepSize1;
                    flip = true;
                }
            }
        }

        return result;
    }
};

int main() {
    return 0;
}

