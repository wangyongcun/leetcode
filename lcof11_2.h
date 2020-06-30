#include <vector>
using namespace std;

int minArray2(vector<int>& nums) {
	if (nums.size() == 0)
	{
		return -1;
	}

	if (nums.size() == 1)///forget this
	{
		return nums[0];
	}

	int p1 = 0;
	int p2 = nums.size() - 1;

	int m = 0;
	while (nums[p1] >= nums[p2])
	{
		m = (p1 + p2) / 2;

		if (p2 - p1 == 1)
		{
			m = p2;
			break;
		}

		if (nums[m] >=nums[p2] ){
			p1 = m;
		}
		else {
			p2 = m;
		}
	}

	return nums[m];
}

void test_lcof11_2()
{
	int num[] = {3,4,5,1,2};
	vector<int> nums(num,num+5);
	printf("%d",minArray2(nums));

	int num2[] = {3,1,3};
	vector<int> nums2(num2,num2+3);
	printf("%d",minArray2(nums2));
}