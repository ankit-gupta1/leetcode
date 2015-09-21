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
    bool isAnagram(string s, string t) {
        bool truth = true;
        map<char, int> charMapS;
        map<char, int> charMapT;

        if (s.length() != t.length()) {
            truth = false;
        } else {
            for (unsigned int i = 0; i < s.length(); i++) {
                charMapS[s[i]]++;
                charMapT[t[i]]++;
            }

            if (charMapS != charMapT) {
                truth = false;
            }
        }

        return truth;
    }
};

int main() {
    Solution s;
    cout << s.isAnagram("cat", "aat") << endl;
    return 0;
}


