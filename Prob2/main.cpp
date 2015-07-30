/*
 * main.cpp
 *
 *  Created on: Jun 21, 2015
 *      Author: ankit
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned int carry = 0;
        ListNode *result;
        ListNode *resultIter;

        if (l1 != NULL && l2 != NULL) {
            ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
            temp->val = (l1->val + l2->val + carry);
            temp->next = NULL;
            result = temp;
            resultIter = result;

            if (resultIter->val > 9) {
                carry = resultIter->val / 10;
                resultIter->val = resultIter->val % 10;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL && l2 != NULL) {
            ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
            temp->val = (l1->val + l2->val + carry);
            temp->next = NULL;
            resultIter->next = temp;
            resultIter = resultIter->next;

            if (resultIter->val > 9) {
                carry = resultIter->val / 10;
                resultIter->val = resultIter->val % 10;
            } else {
                carry = 0;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == NULL) {
            l1 = l2;
        }

        while (l1 != NULL) {
            ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
            temp->val = (l1->val + carry);
            temp->next = NULL;
            resultIter->next = temp;
            resultIter = resultIter->next;

            if (resultIter->val > 9) {
                carry = resultIter->val / 10;
                resultIter->val = resultIter->val % 10;
            } else {
                carry = 0;
            }

            l1 = l1->next;
        }

        if (carry > 0) {
            ListNode *temp = (ListNode *) malloc(sizeof(ListNode));
            temp->val = (carry);
            temp->next = NULL;
            resultIter->next = temp;
            resultIter = resultIter->next;
        }

        return result;
    }
};

using namespace std;

int main() {
    ListNode l1(1);
    ListNode l12(7);
    ListNode l13(9);
    ListNode l21(9);
    ListNode l2(9);
    l2.next = &l21;
    l1.next = &l12;
    l1.next->next = &l13;

    Solution S;

    ListNode *l3 = S.addTwoNumbers(&l1, &l2);

    while (l3 != NULL) {
        cout << l3->val << " ";
        l3 = l3->next;
    }

    return 0;
}
