/*
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *       3
 *      / \
 *     9  20
 *   /  \
 *  15   7
 * return its level order traversal as:
 * [
 *     [3],
 *     [9,20],
 *     [15,7]
 * ]
 */

#include <deque>
#include <iostream>
#include <vector>

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> treeVect;
        vector<int> levelVect;
        if (!root) {
            return treeVect;
        }
        deque<TreeNode *> nodeQueue;
        nodeQueue.push_back(root);
        while (!nodeQueue.empty()) {
            deque<TreeNode *> levelQueue(nodeQueue);
            nodeQueue.clear();
            deque<TreeNode *>::const_iterator idx;
            for (idx = levelQueue.cbegin(); idx != levelQueue.cend(); ++idx) {
                levelVect.push_back((*idx)->val);
                if ((*idx)->left) {
                    nodeQueue.push_back((*idx)->left);
                }
                if ((*idx)->right) {
                    nodeQueue.push_back((*idx)->right);
                }
            }
            treeVect.push_back(levelVect);
            levelVect.clear();
        }

        return treeVect;
    }
};

int main() {
    /*
     *              5
     *             / \
     *            4   8
     *           /   / \
     *          11  13  4
     *         /  \      \
     *        7    2      1
     */
    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution solution;
    vector<vector<int>> treelVect = solution.levelOrder(root);

    std::cout << "[" << std::endl;
    for (size_t i = 0; i < treelVect.size(); ++i) {
        std::cout << "  [";
        for (size_t j = 0; j < treelVect[i].size(); ++j) {
            std::cout << treelVect[i][j];
            if (j + 1 != treelVect[i].size()) {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i + 1 != treelVect.size()) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;

    return 0;
}
