/*
 *   Given a binary tree and a sum, determine if the tree has a root-to-leaf
 path such
 *   that adding up all the values along the path equals the given sum.

 *   For example:
 *   Given the below binary tree and sum = 22,
 *              5
 *             / \
 *            4   8
 *           /   / \
 *          11  13  4
 *         /  \      \
 *        7    2      1
 *
 *   return true, as there exist a root-to-leaf path 5->4->11->2 which sum
 is 22.
 */

#include <iostream>

/**
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return (sum == root->val);
        }
        if (root->left) {
            if (hasPathSum(root->left, sum - root->val)) {
                return true;
            }
        }
        if (root->right) {
            if (hasPathSum(root->right, sum - root->val)) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution sol;

    std::cout << sol.hasPathSum(root, 22) << std::endl;

    return 0;
}
