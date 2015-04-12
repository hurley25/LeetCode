/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
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
	void maxDepthSearch(TreeNode *root, int curDepth, int &maxDepth) {
		if (!root) {
			return;
		}
		if (!root->left && !root->right) {
			if (maxDepth < curDepth) {
				maxDepth = curDepth;
			}
		} else {
			maxDepthSearch(root->left, curDepth + 1, maxDepth);
			maxDepthSearch(root->right, curDepth + 1, maxDepth);
		}
	}

public:
	int maxDepth(TreeNode *root) {
		int maxDepth = INT_MIN;
		int curDepth = 1;

		if (!root) {
			return 0;
		} else {
			maxDepthSearch(root, curDepth, maxDepth);
		}

		return maxDepth;
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
	*              \
	*               5
	*/
	TreeNode *root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->right = new TreeNode(8);

	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->left->left->right->right = new TreeNode(5);

	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	Solution solution;

	cout << solution.maxDepth(root) << endl;

	return 0;
}
