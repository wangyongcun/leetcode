/// https://leetcode-cn.com/problems/multiply-strings/
#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {

	vector<vector<int>> re = vector<vector<int>>(text2.size(), vector<int>(text1.size(), 0));

	for (int j = 0; j < text2.length(); j++)
	{
		for (int i = 0; i < text1.length(); ++i) {
			int max1 = 0;
			int max2 = 0;
			int max3 = 0;
			if (i - 1 >= 0)
				max1 = re[j][i - 1];
			if (j - 1 >= 0) {
				max2 = re[j - 1][i];
			}
			if (i-1 >= 0 && j-1>=0 ){
				max3 = re[j - 1][i - 1];
			}
			if (text2[j] == text1[i]) {
				printf("%c", text1[i]);
				re[j][i] = max3 + 1;
			}
			else {
				re[j][i] = max(max1, max2);
			}
		}
	}

	return re[text2.length()-1][text1.length()-1];
}

void test_leet1143() {
	//string str1 = "bsbininm";
	//string str2 = "jmjkbkjkv";
	string str1 = "abcde";
	string str2 = "ace";
	int re = longestCommonSubsequence(str1, str2);
}
