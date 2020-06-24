#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
	int i = 0;
	int j = height.size() - 1;
	int max = min(height[i], height[j]) * (j - i);
	while (i<j){
		if (height[i] > height[j]) {
			--j;
		}
		else
		{
			++i;
		}

		max = std::max(min(height[i],height[j])*(j-i),max);
	}

	return max;
}

void test_leet11() {
	vector<int> v = { 1,8,6,2,5,4,8,3,7 };
	printf("%d", maxArea(v));
}
