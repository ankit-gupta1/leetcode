/*
 * main.cpp
 *
 *  Created on: Sep 15, 2015
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
    int hIndex(vector<int>& citations) {
        int currHidx = 0;
        int maxHidx = currHidx;

        sort(citations.begin(), citations.end());
        for (vector<int>::iterator iter = citations.begin(); iter != citations.end(); iter++) {
            currHidx = citations.end() - iter >= *iter ? *iter : citations.end() - iter;

            if (currHidx > maxHidx) {
                maxHidx = currHidx;
            }
        }

        return maxHidx;
    }
};

int main() {
    vector<int> citations { 100 };
    Solution s;
    cout << s.hIndex(citations) << endl;
    return 0;
}

