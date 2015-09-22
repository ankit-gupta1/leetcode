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
#include <deque>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }

        return num % 9 != 0 ? num % 9 : 9;
    }
};

int main() {
    return 0;
}
