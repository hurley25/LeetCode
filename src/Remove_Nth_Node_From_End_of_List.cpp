/*
 * Given a linked list, remove the nth node from the end of list and return its
 *head. For example, Given linked list: 1->2->3->4->5, and n = 2. After removing
 *the second node from the end, the linked list becomes 1->2->3->5. Note: Given
 *n will always be valid. Try to do this in one pass.
 */

#include <cmath>
#include <iostream>

using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pBefore = head;
        ListNode *pAfter = head;
        ListNode *del = NULL;

        int i = 0;
        while (pAfter && i < n + 1) {
            pAfter = pAfter->next;
            i++;
        }
        if (!pAfter && i != n + 1) {
            del = pBefore;
            pBefore = pBefore->next;
            delete del;
            return pBefore;
        }
        while (pAfter) {
            pBefore = pBefore->next;
            pAfter = pAfter->next;
        }
        del = pBefore->next;
        pBefore->next = pBefore->next->next;
        delete del;

        return head;
    }
};

int main() {
    ListNode *list = new ListNode(1);

    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next = NULL;

    Solution solution;
    ListNode *p = solution.removeNthFromEnd(list, 5);

    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
