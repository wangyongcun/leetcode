/// https://leetcode-cn.com/problems/multiply-strings/
#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
	vector<int> vdp = vector<int>(nums.size(), 0);
	vdp[0] = 1;
	for (int i=1;i<nums.size();++i){
		int maxdp = 0;
		for (int j=0;j<i;++j)
		{
			if (nums[j]<nums[i]){
				if (vdp[j] > maxdp)
					maxdp = vdp[j];
			}
		}

		vdp[i] = maxdp + 1;
	}

	int maxDP = 0;
	for (int i=0;i<vdp.size();++i)
	{
		if (vdp[i]>maxDP){
			maxDP = vdp[i];
		}
	}

	return maxDP;
}

void test_leet300() {
	vector<int> v = { 1, 3, 5, 4, 7};
	printf("%d", lengthOfLIS(v));
}
