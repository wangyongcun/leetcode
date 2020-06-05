#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(0), right(0) {}
	
};

TreeNode* bt(vector<int>& preorder, vector<int>& inorder, int p1, int p2, int i1, int i2) {

	if (p2 < p1 || i2 < i1)
		return 0;

	TreeNode* root = new TreeNode(preorder[p1]);

	if (p1==p2){
		return root;
	}/// miss above 3lines , so 
	///root->left = bt(preorder, inorder, p1 + 1, np - 1, i1, ni - 1);  enter into deadlock

	int np = p1 + 1;
	int ni = i1;
	for (int j = i1; j <= i2; ++j) {
		if (inorder[j] != preorder[p1]) {
			np++;
			ni++;
		}
		else {
			break;
		}
	}
	printf("%d,%d\n", np, ni);
	root->left = bt(preorder, inorder, p1 + 1, np - 1, i1, ni - 1);
	root->right = bt(preorder, inorder, np, p2, ni + 1, i2);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return bt(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
}

void test_lcof07() {
	vector<int> pre = { 3,9,20,15,7 };
	vector<int> in = { 9,3,15,20,7 };
	TreeNode* root = buildTree(pre, in);
}