/*
 * main.cpp
 *
 *  Created on: Sep 20, 2015
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
    map<int, string> firstDigit;
    map<int, string> secondDigit;

    Solution() {
        this->firstDigit[1] = "One";
        this->firstDigit[2] = "Two";
        this->firstDigit[3] = "Three";
        this->firstDigit[4] = "Four";
        this->firstDigit[5] = "Five";
        this->firstDigit[6] = "Six";
        this->firstDigit[7] = "Seven";
        this->firstDigit[8] = "Eight";
        this->firstDigit[9] = "Nine";
        this->firstDigit[10] = "Ten";
        this->firstDigit[11] = "Eleven";
        this->firstDigit[12] = "Twelve";
        this->firstDigit[13] = "Thirteen";
        this->firstDigit[14] = "Fourteen";
        this->firstDigit[15] = "Fifteen";
        this->firstDigit[16] = "Sixteen";
        this->firstDigit[17] = "Seventeen";
        this->firstDigit[18] = "Eighteen";
        this->firstDigit[19] = "Nineteen";
        this->secondDigit[2] = "Twenty";
        this->secondDigit[3] = "Thirty";
        this->secondDigit[4] = "Forty";
        this->secondDigit[5] = "Fifty";
        this->secondDigit[6] = "Sixty";
        this->secondDigit[7] = "Seventy";
        this->secondDigit[8] = "Eighty";
        this->secondDigit[9] = "Ninety";
    }

    int getNumDigits(int num) {
        int numOfDigits = 0;

        while (num > 0) {
            num = num / 10;
            numOfDigits++;
        }

        return numOfDigits;
    }

    string threeDigitsToWords(int num) {
        string threeDigits;
        if (num == 0) {
            return threeDigits;
        }

        bool preSpace = false;

        int numOfDigits = getNumDigits(num);
        if (numOfDigits == 3) {
            threeDigits.append(this->firstDigit[num / 100]);
            threeDigits.append(" Hundred");
            preSpace = true;
        }

        int secondDigit = (num / 10) % 10;
        if (secondDigit > 1) {
            if (preSpace) {
                threeDigits.append(" ");
            }

            threeDigits.append(this->secondDigit[secondDigit]);

            int firstDigit = num % 10;
            if (firstDigit > 0) {
                threeDigits.append(" ");
                threeDigits.append(this->firstDigit[firstDigit]);
            }
        } else if (secondDigit <= 1 && (num % 100) > 0) {
            if (preSpace) {
                threeDigits.append(" ");
            }

            int remaining = num % 100;
            if (remaining > 0) {
                threeDigits.append(this->firstDigit[remaining]);
            }
        }

        return threeDigits;
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        string integerName;
        bool preSpace = false;
        int numDigits = getNumDigits(num);
        int orders = numDigits / 3;

        if (orders == 3) {
            integerName = threeDigitsToWords(num / 1000000000);

            if (numDigits > 9) {
                integerName.append(" Billion");
                preSpace = true;
            }

            orders--;
        }

        if (orders == 2 && num % 1000000000 > 0) {
            int temp = (num / 1000000) % 1000;

            if (preSpace && temp > 0) {
                integerName.append(" ");
            }

            integerName.append(threeDigitsToWords(temp));

            if (numDigits > 6 && temp > 0) {
                integerName.append(" Million");
                preSpace = true;
            }

            orders--;
        }

        if (orders == 1 && num % 1000000 > 0) {
            int temp = (num / 1000) % 1000;

            if (preSpace && temp > 0) {
                integerName.append(" ");
            }

            integerName.append(threeDigitsToWords(temp));

            if (numDigits > 3 && temp > 0) {
                integerName.append(" Thousand");
                preSpace = true;
            }

            orders--;
        }

        if (orders < 1 && num % 1000 > 0) {
            if (preSpace) {
                integerName.append(" ");
            }

            integerName.append(threeDigitsToWords(num % 1000));
        }

        return integerName;
    }
};

int main() {
    Solution s;
    cout << s.numberToWords(1000010) << endl;
    cout << s.numberToWords(33618311) << endl;
    return 0;
}

