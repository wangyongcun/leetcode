#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> re;
	if (nums.size() < 3)
		return re;

	std::sort(nums.begin(), nums.end());


	for (int i = 0; i < nums.size() - 2; ++i)
	{
		int target = 0 - nums[i];
		if (i >= 1 && nums[i] == nums[i - 1]) {
			continue;
		}

		int m = i + 1;
		int n = nums.size() - 1;
		while (m < n) {
			if (nums[m] + nums[n] > target) {
				n--;
			}
			else if (nums[m] + nums[n] < target)
			{
				m++;
			}
			else
			{
				vector<int> v;
				v.push_back(nums[i]);
				v.push_back(nums[m]);
				v.push_back(nums[n]);
				re.push_back(v);
				n--;
				++m;
				while (nums[n] == nums[n - 1] && n > 0 && n > m) {
					n--;
				}
				while (nums[m] == nums[m - 1] && n > m) {
					++m;
				}
			}
		}
	}

	return re;
}
void test_leet15() {
	vector<int> v = { -1, 0, 1, 2, -1, -4 };
	auto re = threeSum(v);
	//printf("%d", maxArea(v));
}
