#pragma once
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//
//int comp(const void* s1, void const* s2){
//	char t1[22] = {0};
//	char t2[22] = {0};
//	sprintf(t1,"%s%s", (char*)s1, (char*)s2);
//	sprintf(t2,"%s%s", (char*)s2, (char*)s1);
//	return strcmp(t1, t2);
//}
//string minNumber(vector<int>& nums) {
//	string re;
//	int len = nums.size();
//	if (len == 0)
//		return re;
//
//	char** pstr =(char**) new char*[len];
//	for (int i = 0; i < len;++i) {
//		pstr[i] = new char[11];
//		sprintf(pstr[i], "%d", nums[i]);
//	}
//	
//	qsort(pstr, len, sizeof(pstr[0]), comp);
//
//	for (int i = 0; i < len; ++i) {
//		delete pstr[i];
//	}
//
//	delete pstr;
//	
//	return re;
//}
//

static bool compare(const string& a, const string& b)
{
	return a + b < b + a;
}

string minNumber(vector<int>& nums) {
	vector<string> strs;
	string res;
	for (auto num : nums)
		strs.push_back(to_string(num));
	std::sort(strs.begin(), strs.end(), compare);
	for (auto str : strs)
		res += str;
	return res;
}

void test_lcof45() {
	vector<int> in = { 30,3,45,12 };
	string re = minNumber(in);
}
