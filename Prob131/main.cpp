/*
 * main.cpp
 *
 *  Created on: Oct 7, 2015
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
    vector<vector<bool> > possiblePalindromes(string s) {
        vector<bool> temp(s.length(), false);
        vector<vector<bool> > isPal(s.length(), temp);

        for (unsigned int i = 0; i < s.length(); i++) {
            isPal[i][i] = true;
        }

        for (unsigned int j = 1; j < s.length(); j++) {
            for (unsigned int i = 0; i < j; i++) {
                if (s[j] == s[i]) {
                    if ((j - i > 1)) {
                        if (isPal[i + 1][j - 1]) {
                            isPal[i][j] = true;
                        }
                    } else {
                        isPal[i][j] = true;
                    }
                }
            }
        }

        return isPal;
    }

    vector<vector<string> > partition(string s) {
        vector<vector<bool> > isPal = possiblePalindromes(s);
        map<unsigned int, vector<vector<string> > > partMap;

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < (int) s.length(); j++) {
                if (isPal[i][j] == true) {
                    string currString = s.substr(i, j - i + 1);

                    if (j == (int) (s.length() - 1)) {
                        vector<string> strList;
                        strList.insert(strList.begin(), currString);
                        partMap[i].insert(partMap[i].begin(), strList);
                    } else {
                        vector<vector<string> > tempList = partMap[j + 1];
                        for (vector<vector<string> >::iterator iter = tempList.begin(); iter != tempList.end();
                                iter++) {
                            (*iter).insert((*iter).begin(), currString);
                        }

                        for (vector<vector<string> >::iterator iter = tempList.begin(); iter != tempList.end();
                                iter++) {
                            partMap[i].insert(partMap[i].begin(), *iter);
                        }
                    }
                }
            }
        }

        return partMap[0];
    }
};

int main() {
    Solution s;
    string str = "aab";
    vector<vector<string> > sol = s.partition(str);
    for (vector<vector<string> >::iterator iter1 = sol.begin(); iter1 != sol.end(); iter1++) {
        for (vector<string>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++) {
            cout << *iter2 << ", ";
        }

        cout << endl;
    }
    return 0;
}

