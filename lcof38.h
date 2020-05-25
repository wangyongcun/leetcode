#pragma once
#include <vector>
#include <string>
using namespace std;

void permutation(string& s, int b, vector<string>& re) {

	for (int i = b + 1; i < s.size(); ++i)
	{
		swap(s[b], s[i]);
		permutation(s, b + 1, re);
		re.push_back(s);
		swap(s[b], s[i]);
	}
}

vector<string> permutation(string s) {
	vector<string> re;
	if (s.size() == 1)
	{
		re.push_back(s);
	}

	permutation(s, 0, re);
	return re;
}



void test_lcof38() {
	vector<string>& re = permutation("abc123");
}