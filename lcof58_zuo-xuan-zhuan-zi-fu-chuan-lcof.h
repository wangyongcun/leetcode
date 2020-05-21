///https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/

#include "common.h"

string reverseLeftWords(string s, int n) {

	if (s.size()<=1)
	{
		return s;
	}

	reverse(s,0,n-1);
	reverse(s,n,s.size()-1);
	reverse(s,0,s.size()-1);

	return s;
}

void test_lcof58()
{
	string s = "abcdefg";

	printf("%s",reverseLeftWords(s,2).c_str());

	string s2 = "lrloseumgh";

	printf("%s",reverseLeftWords(s2,6).c_str());
}