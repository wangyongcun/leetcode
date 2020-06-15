#pragma once
#include <vector>
#include <algorithm>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size() == 0) {
		return 0;
	}

	vector<int> vTmp;
	for (int i = triangle.size() - 1; i >= 0; --i) {
		for (int j = 0; j < triangle[i].size(); ++j) {
			if (i == triangle.size() - 1) {
				vTmp.push_back(triangle[i][j]);
			}
			else {
				vTmp[j] = min(triangle[i][j] + vTmp[j], triangle[i][j] + vTmp[j + 1]);
				printf("%d,", vTmp[j]);
			}
		}
		printf("\r\n");

		if (triangle[i].size() == 1) {
			return vTmp[0];
		}
	}

	return 0;
}

void test_leet120(){
	vector<vector<int>> v = { 
		{2} ,
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3} };

	minimumTotal(v);
}