#pragma once
#include <vector>
using namespace std;
///https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
///13 / 22 个通过测试用例
/// failed at [179, 437, 1405, 5227, 8060, 8764, 8248, 4687, 3297, 13038, 12691, 15744, 16195, 15642, 19813, 17128, 21051, 20707, 22177, 21944, 23644, 23281, 19970, 23652, 26471, 31467, 33810, 32300, 33880, 27334, 25987, 35643, 35103, 36489, 42534, 42990, 42942, 37090, 36075, 34516, 16624, 11335, 10737, 44641, 45754, 47096, 46021, 49150, 48013, 49814, 51545, 52555, 50701, 47875, 56783, 57558, 53812, 62008, 61737, 63052, 63478, 62799, 59246, 64765, 64066, 63862, 65384, 67449, 66552, 57741, 45618, 44412, 667, 69718, 75519, 76819, 72971, 79319, 78145, 80615, 84280, 80984, 86598, 85903, 84334, 80867, 87993, 92361, 88465, 87738, 80364, 94380, 94446, 96785, 93694, 76847, 99655, 98675, 97001, 72112]
bool check(vector<int>& postorder, int b, int e) {

	if (e - b <= 2)
		return true;
	int fb = e - b;//1,2,3

	for (int i = 0; i < (e - b); ++i) {
		if (postorder[i]>postorder[fb]){
			fb = i;
			break;
		}
	}

	if (fb == b) {
		for (int i = fb; i < e - 1; ++i)
		{
			if (postorder[i] <= postorder[e - b]) {
				return false;
			}
		}

		return check(postorder, b, e - 1);
	}
	else if (fb == e - b) {
		return check(postorder, b, e - 1);
	}
	else
	{
		for (int i = fb; i < e - 1; ++i)
		{
			if (postorder[i] <= postorder[e - b]) {
				return false;
			}
		}

		return check(postorder, b, fb - 1) && check(postorder, fb, e - 1);
	}

}

bool verifyPostorder(vector<int>& postorder) {
	return check(postorder, 0, postorder.size() - 1);
}

void test_lcof33()
{
	vector<int> v = { 7, 4, 6, 5};
	printf("%d", verifyPostorder(v));
}