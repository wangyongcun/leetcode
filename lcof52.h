///https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
#pragma once 

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(0) {}
	
};

int getlen(ListNode* l) {
	int n = 0;
	while(l){
		++n;
		l = l->next;
	}

	return n;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	if (headA == 0 || headB == 0)
		return 0;

	int l1 = getlen(headA);
	int l2 = getlen(headB);

	int count = 0;
	if (l1 > l2) {
		while (headA != 0 && count < l1-l2)
		{
			headA = headA->next;
			count++;
		}
	}
	else if (l1 < l2) {
		count = 0;
		while (headB != 0 && count < l2 - l1)
		{
			headB = headB->next;
			count++;
		}
	}

	while (headA && headB)
	{
		if (headA == headB)
		{
			return headA;
		}

		headA = headA->next;
		headB = headB->next;
	}

	return 0;
}