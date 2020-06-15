#include "stdafx.h"
#include <vector>
using namespace std;

bool addStr(char* str,int n) {
	bool carr = 0;
	for (int i = strlen(str) - 1; i >= 0; --i) {
		if (str[i] == '9') {
			if (strlen(str)-1-i == n-1) {
				return true;
			}
			str[i] = '0';
		}
		else {
			str[i] = str[i] + 1;
			break;
		}
	}
	return false;
}

vector<int> printNumbers(int n) {
	vector<int> re;
	if (n == 0)
		return re;

	char str[11] = "0000000000";
	int i = 0;
	bool bBreak = false;
	while (1) {
		bBreak = addStr(str,n);
		if (bBreak)
			break;
		int t = atoi(str);
		re.push_back(t);
	}

	return re;
}

void test_lcof17()
{
	printNumbers(3);
}