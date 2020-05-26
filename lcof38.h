#pragma once
#include <vector>
#include <string>
using namespace std;

void permutation(string& s, int b, vector<string>& re) {

	if (b == s.size()-1)
		re.push_back(s);///only record at this position is right

	//printf("%s\n", s.c_str());
	for (int i = b ; i < s.size(); ++i)
	{
		if (s[b] != s[i] && b != i) {
			swap(s[b], s[i]);
			///re.push_back(s);///add record at this position will get some duplicate result
			//printf("%s\n",s.c_str());
			permutation(s, b + 1, re);
			swap(s[b], s[i]);
		}
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
	vector<string>& re = permutation("abc");
}