#pragma once
///https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/

/**
 * Definition for a binary tree node.

 */
 /// easy problem,but I make 2 mistake
 /*
 1 left =0 and right != 0 , first edition donnot swap to make mirror
 2 direct swap value ,not modify pointer lead below node still stay the same side
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(0), right(0) {}
};

TreeNode* mirrorTree(TreeNode* root) {
	if (root)
	{
		TreeNode* t = root->left;
		root->left = root->right;
		root->right = t;

		if (root->left)
			mirrorTree(root->left);
		if (root->right)
			mirrorTree(root->right);
	}

	return root;
}
};
