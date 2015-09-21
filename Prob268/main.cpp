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

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingNum;
        int sum = 0;
        int totalElements = nums.size();

        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            sum += *iter;
        }

        missingNum = (totalElements * (totalElements + 1) / 2) - sum;
        return missingNum;
    }
};

int main() {
    return 0;
}


