#include <vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	return 1;
}

void test_lcof04() {

	vector<vector<int>> matrix = {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22 },
		{10, 13, 14, 17, 24 },
		{18, 21, 23, 26, 30} };

	printf("%d", findNumberIn2DArray(matrix, 5));
	printf("%d", findNumberIn2DArray(matrix, 1));
	printf("%d", findNumberIn2DArray(matrix, 18));
	printf("%d", findNumberIn2DArray(matrix, 20));
}