#pragma once

#include <list>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(0), right(0) {}

};

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> re;
	if (root == 0)
		return re;

	stack<TreeNode* > ts;
	TreeNode* cur = root;

	while (cur) {
		if (cur->left) {
			ts.push(cur);
			cur = cur->left;
		}
		else {
			re.push_back(cur->val);
			if (cur->right)
				cur = cur->right;
			else {
				cur = 0;
				while (ts.size() > 0) {
					cur = ts.top();
					ts.pop();
					re.push_back(cur->val);
					if (cur->right) {
						cur = cur->right;
						break;
					}
					else {
						cur = 0;
					}
				}
			}
		}
	}
	return re;
}
