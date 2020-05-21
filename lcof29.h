#pragma once
/// https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/

#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> re;
	if (matrix.size() == 0)
	{
		return re;
	}

	int t = 0; 
	int l = 0;
	int b = matrix.size()-1;
	int r = matrix[0].size()-1;

	while (l<=r && t <= b)
	{
		for (int i=l;i<=r;++i)
		{
			re.push_back(matrix[t][i]);
		}

		for (int i = t+1; i <= b ; ++i)
		{
			re.push_back(matrix[i][r]);
		}

		for (int i = r-1; i >= l; --i)
		{
			if(b != t)
				re.push_back(matrix[b][i]);
		}

		for (int i = b-1; i >= t+1 ; --i)
		{
			if(l != r)
				re.push_back(matrix[i][l]);
		}

		t++;
		l++;
		b--;
		r--;
	}

	return re;
}

void test_lcof29()
{
	vector<vector<int>> input = { {6,9,7} };
	spiralOrder(input);
};// [[1, 2, 3], [4, 5, 6], [7, 8, 9]]