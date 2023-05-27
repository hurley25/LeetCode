/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center). For example, this binary tree is symmetric:
 *      1
 *     / \
 *    2   2
 *   / \ / \
 *  3  4 4  3
 *
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *     3    3
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
    bool isSymmetric(TreeNode *root) { return _isSymmetric(root, root); }

  private:
    bool _isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right || left->val != right->val) {
            return false;
        }

        return _isSymmetric(left->left, right->right) &&
               _isSymmetric(left->right, right->left);
    }
};

int main() {
    /*
     *                5
     *             /    \
     *            4      4
     *           / \    / \
     *          11  5  5   11
     */
    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(11);

    Solution solution;

    cout << solution.isSymmetric(root) << endl;

    return 0;
}
