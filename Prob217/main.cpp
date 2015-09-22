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
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool truth = true;
        set<int> valSet;

        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
            valSet.insert(*iter);
        }

        if (valSet.size() == nums.size()) {
            truth = false;
        }

        return truth;
    }
};

int main() {
    return 0;
}


