#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void tr(vector<string>& vRe, string strRe, int l, int r) {
	if (r < l) {
		return;
	}
	//if (l < 0 || r < 0){
	//	return;
	//}

	if (l > 0)
	{
		tr(vRe, strRe+"(", l-1, r);
		///error ,tr(vRe, strRe+"(", l--, r) ,this can cause deadlock
		///error2  strRe = strRe +"(", write like this will refelect below sentence, below function l parameter didnot reduce
	}

	if (r > 0) {
		tr(vRe, strRe+")", l, r-1);
	}

	if (l == 0 && r == 0) {
		vRe.push_back(strRe);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> vRe;
	int l = n;
	int r = n;
	string strRe;
	tr(vRe,strRe,l, r);
	return vRe;
}

void test_leet22() {
	vector<string> vRe = generateParenthesis(3);
	//printf("%d", maxArea(v));
}
