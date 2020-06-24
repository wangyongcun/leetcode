#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.size() <= 1){
			return nums.size();
		}

		vector<int> dp(nums.size(), 1);
		vector<int> counts(nums.size(), 1);
		for (int i=0;i<nums.size();++i){
			for (int j=0;j<i;++j)
			{
				if (nums[j]<nums[i] ) {
					if (dp[j]+1 > dp[i]){
						dp[i] = dp[j] + 1;
						counts[i] = dp[j] + 1;
					}
					else if (dp[j] + 1 == dp[i]){
						counts[i] += dp[i];
					}
				}
			}
		}

		return *(std::max_element(counts.begin(), counts.end()));
	}
};


int findNumberOfLIS(vector<int>& nums) {
	if (nums.size() <= 1) {
		return nums.size();
	}

	vector<int> dp(nums.size(), 1);
	vector<int> counts(nums.size(), 1);
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}	
			}

			if (nums[j] <= nums[i]){
				if (dp[j] > dp[i]){
					counts[i] = counts[j] ;
				}
				else if (dp[j] +1 == dp[i]){
					counts[i] += counts[j];
				}
			}

		}
	}

	return *(std::max_element(counts.begin(), counts.end()));

}
void test_leet673() {
	vector<int> v = { 1, 3, 5, 4, 7};
	//vector<int> v = { 2, 2, 2, 2, 2 };
	printf("%d", findNumberOfLIS(v));
}
