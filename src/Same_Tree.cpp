/*
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value.
 */

#include <iostream>

using namespace std;

/*
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if ((!p && !q)) {
            return true;
        }
        if ((!p && q) || (p && !q) || p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    /*
     *                5
     *             /    \
     *            4      8
     *           / \    / \
     *          11  5  13  4
     */
    TreeNode *root1 = new TreeNode(5);

    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);

    root1->left->left = new TreeNode(11);
    root1->left->right = new TreeNode(5);

    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);

    TreeNode *root2 = new TreeNode(5);

    root2->left = new TreeNode(4);
    root2->right = new TreeNode(8);

    root2->left->left = new TreeNode(11);
    root2->left->right = new TreeNode(5);

    root2->right->left = new TreeNode(13);
    root2->right->right = new TreeNode(4);

    Solution solution;

    cout << solution.isSameTree(root1, root2) << endl;

    return 0;
}
