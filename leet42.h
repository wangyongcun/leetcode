/// https://leetcode-cn.com/problems/multiply-strings/
#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
	if (height.size() <= 2){
		return 0;
	}

	int i = 0; 
	int j = height.size() - 1; 
	int leftMax = height[i];
	int rightMax = height[j];
	int re = 0;
	while (i<j){
		if (height[i]<=height[j]){
			if (height[i]< leftMax){
				re += leftMax - height[i];
			}
			else
			{
				leftMax = height[i];
			}
			++i;
		}
		else {
			if (height[j] < rightMax){
				re += rightMax - height[j];
			}
			else {
				rightMax = height[j];
			}
			--j;
		}
	}
	return re;
}

void test_leet42() {

	vector<int> input = { 0,1,0,2,1,0,1,3,2,1,2,1 };

	printf("%d", trap(input));
}
