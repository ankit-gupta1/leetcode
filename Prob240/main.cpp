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

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        bool truth = false;

        for (vector<vector<int> >::iterator iter = matrix.begin(); iter != matrix.end(); iter++) {
            vector<int> *currentRow = &(*iter);
            if (target <= currentRow->back() && target >= currentRow->front()) {
                truth = binary_search(currentRow->begin(), currentRow->end(), target);
                if (truth) {
                    break;
                }
            }
        }

        return truth;
    }
};

int main() {
    return 0;
}

