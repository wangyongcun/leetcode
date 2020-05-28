#pragma once
/// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
/// 110 / 114 个通过测试用例
///failed  at [1,-2,-3,1,3,-2,null,-1] -1
#include "lcof27.h"

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	int add = 0;
	vector<vector<int>> re;
	vector<int> path;
	trace(root, re, path, sum, add);
	return re;
}
void trace(TreeNode* root, vector<vector<int>>& re, vector<int>& path, int sum, int add) {

	if (root == 0) {
		return;
	}
	int curAdd = root->val + add;
	if (curAdd == sum) {
		if (root->left == 0 && root->right == 0) {
			path.push_back(root->val);
			re.push_back(path);
			path.pop_back();
		}
	}
	else
	{
		add = curAdd;
		path.push_back(root->val);
		trace(root->left, re, path, sum, add);
		trace(root->right, re, path, sum, add);
		path.pop_back();
	}
}

