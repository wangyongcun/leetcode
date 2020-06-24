#pragma once
#include <vector>
#include <algorithm>
using namespace std;
int maxProduct(vector<int>& nums) {

	if (nums.size()==0){
		return INT_MIN;
	}

	int positive_max = INT_MIN;
	int negtive_min = INT_MAX;
	int tmp = nums[0];
	int re = INT_MIN;
	for (int i=1;i<nums.size();++i)
	{
		tmp = nums[i] * tmp;
		if (tmp > 0){
			positive_max = tmp;
			re = positive_max;
		}
		else if (nums[i] * tmp < 0) {
			negtive_min = tmp;
		}
		
		else if(nums[i] == 0)
		{
			if (re < 0){
				re = 0;
			}

			if (i + 1 < nums.size())
			{
				tmp = nums[i + 1];
				i = i + 1;
				positive_max = INT_MIN;
				negtive_min = INT_MAX;
			}				
		}		
	}

	return re;
}

int maxProduct2(vector<int>& nums) {

	int maxF = nums[0], minF = nums[0], ans = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		int mx = maxF, mn = minF;
		maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
		minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
		ans = max(maxF, ans);
	}
	return ans;
}

void test_leet152(){
	vector<int> v = { -2,0,-1 };
	printf("%d", maxProduct(v));
}