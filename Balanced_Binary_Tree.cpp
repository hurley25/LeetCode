/*
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as
 * a binary tree in which the depth of the two subtrees of every node
 * never differ by more than 1.
 */

#include <iostream>
#include <algorithm>
#include <cmath>

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
	bool isBalanced(TreeNode *root) {
		if (!root || (!root->left && !root->right)) {
			return true;
		}
		if (abs(depth(root->left) - depth(root->right)) > 1) {
			return false;
		}

		return isBalanced(root->left) && isBalanced(root->right);
	}

private:
	int depth(TreeNode *root){
		if (!root) {
			return 0;
		}

		return max(depth(root->left), depth(root->right)) + 1;
	}
};

int main()
{
	/*
	*                5
	*             /    \
	*            4      8
	*           / \    / \
	*          11  5  13  4
	*         /  \      
	*        7    2
	*/
	TreeNode *root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->right = new TreeNode(8);

	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->left->right = new TreeNode(5);

	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);

	Solution solution;

	cout << solution.isBalanced(root) << endl;

	return 0;
}
