///https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
///accept by one try
#include <string>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(0) {}
};

vector<int> reversePrint(ListNode* head) {
	vector<int > re;
	tr(head, re);
	return re;///forget this
}

void tr(ListNode* head, vector<int>& v) {
	if (head)
	{
		if (head->next)
		{
			tr(head->next,v);
		}

		v.push_back(head->val);
	}
}

void test_lcof05() {


}