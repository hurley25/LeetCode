/*
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two
 * lists.
 */

#include <iostream>

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        ListNode *node1, *node2, *head;
        if (l2->val < l1->val) {
            node1 = l2;
            node2 = l1;
        } else {
            node1 = l1;
            node2 = l2;
        }
        head = node1;
        while (node1->next) {
            if ((node1->next)->val <= node2->val) {
                node1 = node1->next;
            } else {
                ListNode *tmp = node1->next;
                node1->next = node2;
                node1 = node2;
                node2 = tmp;
            }
        }
        node1->next = node2;

        return head;
    }
};

int main() {
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(3);
    headA->next->next = new ListNode(5);
    headA->next->next->next = NULL;

    ListNode *headB = new ListNode(7);
    headB->next = new ListNode(8);
    headB->next->next = new ListNode(9);
    headB->next->next->next = NULL;

    Solution solution;
    ListNode *list = solution.mergeTwoLists(headA, headB);
    while (list) {
        cout << list->val << ' ';
        list = list->next;
    }
    cout << endl;

    return 0;
}
