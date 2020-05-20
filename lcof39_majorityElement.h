#include <vector>
using namespace std;
//
int majorityElement(vector<int>& nums) {

	if(nums.size() == 0)
		return -1;

	int time = 1;
	int c = nums[0];
	for(unsigned int i=1;i<nums.size();++i)
	{
		if(nums[i] == c)
		{
			++time;
		}
		else
		{
			--time;
			if(time<=0)
			{
				time = 1;
				c = nums[i];
			}
		}
	}

	return c;
}

void test_lcof39()
{
	int num[] = { 1, 2, 3, 2, 2, 2, 2, 4, 4};
	vector<int> nums(num,num+9);

	printf("%d",majorityElement(nums));
}