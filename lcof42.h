#pragma once
///https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	int max = INT_MIN;
	int cur_max = 0;
	for (int i = 0; i < nums.size(); ++i) {
		cur_max += nums[i];
		if (cur_max > max)
			max = cur_max;
		if (cur_max < 0)
			cur_max = 0;
	}

	return max;
}
void test_lcof42()
{
	vector<int> in = { -2,1,-3,4,-1,2,1,-5,4 };
	int re = maxSubArray(in);
}