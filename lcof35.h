#pragma once
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = 0;
		random = 0;
	}
};

Node* detacheNode(Node* head)
{
	Node* nh = head->next;
	Node* cur = head;
	Node* ncur = nh;
	while (cur && cur->next)/// cur may be null,so cur->next crushed, miss judge null during first time
	{
		cur->next = cur->next->next;
		if (cur->next == 0)///miss judge null during first time
			ncur->next = 0;
		else
			ncur->next = cur->next->next;

		cur = cur->next;
		ncur = ncur->next;
	}

	return nh;
}

void addNode(Node* head) {
	Node* cur = head;
	while (cur != 0)
	{
		Node* nn = new Node(cur->val);
		Node* curNext = cur->next;
		cur->next = nn;
		nn->next = curNext;

		cur = nn->next;
	}

	cur = head;
	while (cur != 0)
	{
		if (cur->random == 0) ///miss judge null during first time
			cur->next->random = 0;
		else
			cur->next->random = cur->random->next;

		cur = cur->next->next;
	}
}

Node* copyRandomList(Node* head) {
	if (head == 0)
		return 0;

	addNode(head);
	return detacheNode(head);
}
