/*
 * main.cpp
 *
 *  Created on: Jun 21, 2015
 *      Author: ankit
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		map<int, vector<unsigned int> > numIdx;

		for (unsigned int i = 0; i < nums.size(); i++) {
			numIdx[nums[i]].push_back(i + 1);
		}

		sort(nums.begin(), nums.end());

		unsigned int l = 0;
		unsigned int r = nums.size() - 1;
		int sum = nums[l] + nums[r];

		while (l < r && sum != target) {
			if (sum > target) {
				sum -= nums[r--];
				sum += nums[r];
			} else {
				sum -= nums[l++];
				sum += nums[l];
			}
		}

		result.push_back(numIdx[nums[l]][0]);
		numIdx[nums[l]].erase(numIdx[nums[l]].begin());
		result.push_back(numIdx[nums[r]].back());
		sort(result.begin(), result.end());
		return result;
	}
};

int main() {
	return 0;
}
