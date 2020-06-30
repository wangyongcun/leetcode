///https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
///accept by one try
#include <string>
using namespace std;

string replaceSpace(string s) {
	if (s.size() == 0) {
		return s;
	}

	int blankNum = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ')
			++blankNum;
	}

	if (blankNum == 0)
		return s;

	int k = s.size() - 1;
	s.resize(s.size() + blankNum * 2);
	int j = s.size() - 1;
	while (blankNum > 0) {
		if (s[k] != ' ')
			s[j--] = s[k--];
		else {
			s[j--] = '0';//miss ;
			s[j--] = '2';//miss ;
			s[j--] = '%';//miss ;
			--k;
			--blankNum;
		}
	}

	return s;//miss this
}

void test_lcof05() {


}