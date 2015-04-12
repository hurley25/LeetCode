/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from 
 * the root node down to the nearest leaf node.
*/

#include <iostream>
#include <string>

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
private:
	void minDepthSearch(TreeNode *root, int curDepth, int &minDepth) {
		if (!root || curDepth >= minDepth) {
			return;
		}
		if (!root->left && !root->right) {
			minDepth = curDepth;
		} else {
			minDepthSearch(root->left, curDepth + 1, minDepth);
			minDepthSearch(root->right, curDepth + 1, minDepth);
		}
	}

public:
	int minDepth(TreeNode *root) {
		int minDepth = INT_MAX;
		int curDepth = 1;

		if (!root) {
			return 0;
		} else {
			minDepthSearch(root, curDepth, minDepth);
		}

		return minDepth;
	}
};

int main()
{
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

	cout << solution.minDepth(root) << endl;

	return 0;
}
