///https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
 int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL)
{}
};

int maxDepth(TreeNode* root) {
	int max = 0;
	int cur = 0;
	trace(root,max,cur);
	return max;
}

void trace(TreeNode* root,int& max,int cur)
{
	if(root)
		++cur;
	else 
		return;

	if(cur > max)
	{
		max = cur;
	}

	trace(root->left,max,cur);

	trace(root->right,max,cur);
}