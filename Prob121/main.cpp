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
    int maxProfit(vector<int>& prices) {
        int maxiProfit = 0;
        int minPrice = INT_MAX;

        for (vector<int>::iterator iter = prices.begin(); iter != prices.end(); iter++) {
            maxiProfit = max(maxiProfit, *iter - minPrice);
            minPrice = min(minPrice, *iter);
        }

        return maxiProfit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {1, 2};
    cout << s.maxProfit(prices) << endl;
    return 0;
}


