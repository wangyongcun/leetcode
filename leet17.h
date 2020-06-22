/// https://leetcode-cn.com/problems/multiply-strings/
#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void permutation(string digits, int begin, vector<string>& re, vector<string>& temple, string& strT) {

	if (begin >= digits.size() )
	{
		return;
	}

	for (int i = 0; i < temple[digits[begin] - '0'].size(); ++i)
	{
		strT[begin] = temple[digits[begin] - '0'][i];

		permutation(digits, begin + 1, re, temple, strT);

		if (begin == digits.size() - 1)
		{
			re.push_back(strT);
		}
	}
}
vector<string> letterCombinations(string digits) {
	vector<string> re;
	vector<string> temple = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	string strT;
	strT.resize(digits.size(), ' ');
	permutation(digits, 0, re, temple, strT);
	return re;
}



void test_leet17() {
		
	letterCombinations("23");
}
