#pragma once
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = 0;
		right = 0;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

void tb(Node* root, Node** lastN) {
	if (root == 0)
	{
		return;
	}

	if (root->left)
	{
		tb(root->left, lastN);
	}
	if (*lastN != 0) {
		(*lastN)->right = root;
		root->left = (*lastN);
	}

	*lastN = root;///forget update this lastN value

	printf("%d,", root->val);

	if (root->right)
	{
		tb(root->right, lastN);
	}
}
Node* treeToDoublyList(Node* root) {

	Node* phead = 0;
	Node* LastN = 0;

	tb(root, &LastN);
///begin 
	phead = LastN;
	while (phead)
	{
		if (phead->left == 0)
			break;

		phead = phead->left;
	}
	 
///end  missed this part for the first submission

	if (phead) {
		phead->left = LastN;
		LastN->right = phead;
	}

	return phead;
}
};
