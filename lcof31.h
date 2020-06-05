#pragma once
// https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
#include <vector>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	if (pushed.size() != popped.size())
		return false;

	stack<int> s;
	int index = 0;
	int sp = pushed.size();
	int i = 0;

	for (; i < popped.size(); ++i) {

		if(s.size() == 0){
			if(index < sp)
				s.push(pushed[index++]);
		}

		while (popped[i] != s.top() && index < sp){
			if (index < sp)
				s.push(pushed[index++]);
		}

		/*if (s.size()> 0) */  ///no need
		{
			if (popped[i] == s.top()) {
				s.pop();
			}
			else{
				return false;
			}
		}		
	}


	if (index >= sp && i >= popped.size() && s.size() == 0)
	{
		return true;
	}

	return false;
}

void test_lcof31()
{
	vector<int> in = { 1, 2, 3, 4, 5 };
	vector<int> out = {4, 5, 3, 2, 1};
	printf("%d", validateStackSequences(in, out));
}