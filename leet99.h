#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(0), right(0) {}

};

///������ӡ���ܹ��ռ临�Ӷ�O��1��Ҫ���±�������leetcode��ʱ����֪����ô����
class Solution {
public:
	void recoverTree(TreeNode* root) {
		while (root) {
			//printf("??? root is 0,return");
			if (root->left) {
				TreeNode* pre = root->left;
				while (pre->right && pre->right != root) {
					pre = pre->right;
					//printf("### root is 0,return");
				}

				if (pre->right == 0) {
					pre->right = root;
					root = root->left;
				}
				else {
					//printf("output node:%d\n",root->val);
					root = root->right;
					if (root) {
						//printf("goto right subtree:%d",root->val);
					}
					else {
						//printf("root is 0,return!!!");
					}
				}
			}
			else {
				//printf("output  node: %d\n,goto:%d",root->val,root->right->val);
				root = root->right;
			}

		}
	}
};