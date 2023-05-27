/*
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins. For example, the following two linked lists: A: a1 → a2
 *                      ↘
 *                       c1 → c2 → c3
 *                      ↗
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns. You may assume there are no cycles anywhere in the entire linked
 * structure. Your code should preferably run in O(n) time and use only O(1)
 * memory.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        } else if (headA == headB) {
            return headA;
        }

        ListNode *p1 = headA;
        int count1 = 0;
        while (p1->next != NULL) {
            count1++;
            p1 = p1->next;
        }

        ListNode *p2 = headB;
        int count2 = 0;
        while (p2->next != NULL) {
            count2++;
            p2 = p2->next;
        }

        p1 = headA;
        p2 = headB;
        // 从尾部对齐两个链表
        if (count1 > count2) {
            for (int i = 0; i < count1 - count2; ++i) {
                p1 = p1->next;
            }
        } else if (count1 < count2) {
            for (int i = 0; i < count2 - count1; ++i) {
                p2 = p2->next;
            }
        }

        while (p1 != p2 && p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 == p2) {
            return p1;
        }

        return NULL;
    }
};

int main() {
    // length: 3
    ListNode *headC = new ListNode(0);
    headC->next = new ListNode(0);
    headC->next->next = new ListNode(0);
    headC->next->next->next = NULL;

    // length: 2 + 3
    ListNode *headA = new ListNode(0);
    headA->next = new ListNode(0);
    headA->next->next = headC;

    // length: 3 + 3
    ListNode *headB = new ListNode(0);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(0);
    headB->next->next->next = headC;

    Solution solution;
    cout << solution.getIntersectionNode(headA, headB) << endl;

    return 0;
}
