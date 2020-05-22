// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
#include "lcof27.h"
#include <vector>
#include <deque>
using namespace std;

vector<int> levelOrder(TreeNode* root) {
	deque<TreeNode*> dq;
	vector<int> re;
	if (root) {
		dq.push_back(root);
	}

	while (dq.size() > 0) {
		TreeNode* pCur = dq.front();
		dq.pop_front();

		re.push_back(pCur->val);

		if (pCur->left)
			dq.push_back(pCur->left);

		if (pCur->right)
			dq.push_back(pCur->right);
	}

	return re;
}