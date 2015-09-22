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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> slideMax;

        if (nums.size() > 0 && (unsigned int) k < nums.size()) {
            deque<int> slideList;

            for (vector<int>::iterator iter = nums.begin(); iter != nums.begin() + k; iter++) {
                while (!slideList.empty() && *iter > slideList.back()) {
                    slideList.pop_back();
                }

                slideList.push_back(*iter);
            }

            slideMax.push_back(slideList.front());
            for (vector<int>::iterator iter = nums.begin() + k; iter != nums.end(); iter++) {
                if (*(iter -  k) == slideList.front()) {
                    slideList.pop_front();
                }

                while (!slideList.empty() && *iter > slideList.back()) {
                    slideList.pop_back();
                }

                slideList.push_back(*iter);
                slideMax.push_back(slideList.front());
            }
        } else if (nums.size() > 0 && (unsigned int) k >= nums.size()) {
            make_heap(nums.begin(), nums.end());
            slideMax.push_back(nums.front());
        }

        return slideMax;
    }
};

int main() {
    vector<int> testVec = { 9, 10, 9, -7, -4, -8, 2, -6 };
    int slideWindowLen = 5;
    Solution s;
    vector<int> response = s.maxSlidingWindow(testVec, slideWindowLen);

    for (vector<int>::iterator iter = response.begin(); iter != response.end(); iter++) {
        cout << *iter << ", ";
    }
    cout << endl;

    return 0;
}

