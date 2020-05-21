///https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/

#include "common.h"

string reverseWords(string s) {

	if(s.size()<=2)
		return s;

	int p1 = 0;
	int p2 = 0;
	while(p1 < s.size())
	{
		if (s[p1] == ' ')
		{
			p1++;
		}
		else if(s[p2] !=' ' && s[p2] != '\0')
		{
			p2++;
		}
		else
		{
			reverse(s,p1,p2-1);
			p1 = p2+1;
			p2 = p1+1;
		}
	}

	reverse(s,0,s.size()-1);

	return s;
}

void test_lcof58_2()
{
	string s = "the sky is blue";
	printf("%s",reverseWords(s).c_str());

}