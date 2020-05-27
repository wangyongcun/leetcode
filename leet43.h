/// https://leetcode-cn.com/problems/multiply-strings/
#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string multiply(string num1, string num2) {

	if (num1 == "0" || num2 == "0")//failed check this for first time
		return "0";

	string re;
	int l1 = num1.size();
	int l2 = num2.size();
	if (l1 == 0 || l2 == 0)
		return re;

	char* re2 = new char[l1+l2+2];
	memset(re2, '0', l2 + l1 + 2);

	re2[l2 + l1 ] = '\0'; ///failed add this line for first time

	for (int j = l2 - 1; j >= 0; --j)
	{
		for (int i = l1 - 1; i >= 0; --i)
		{
			int sum = re2[i + j+1]-'0' + (num1[i] - '0') * (num2[j] - '0');
			re2[i + j + 1] = sum%10 +'0';
			re2[i + j] = sum / 10 + re2[i + j];//failed add( re2[i + j];) for first time
		}
	}

	int i = 0;
	for (;i<l2+l1+2;++i)
	{
		if (re2[i] != '0'){
			break;
		}
	}

	re = re2+i;
	delete [] re2;
	return re;
}

void test_leet43() {
	string str1 = "123";
	string str2 = "456";

	string re = multiply(str1,str2);
}
