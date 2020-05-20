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

int partion(vector<int>& nums,int b,int e)
{
	int m = nums[b];

	while (b < e)
	{
		if (nums[b] < m)
		{
			++b;
		}
		else if (nums[e] >= m)
		{
			--e;
		}
		else if (e > b)
		{
			int t = nums[b];
			nums[b] = nums[e];
			nums[e] = t;
		}
	}

	if (nums[b] > m)
		b--;

	return b;
}

int majorityElement2(vector<int>& nums) {

	int p = partion(nums,0,nums.size()-1);
	
	while (p != nums.size()/2)
	{
		if(p > nums.size()/2){
			p = partion(nums,0,p-1);
		}
		else {//p < nums.size()/2
			p = partion(nums,p+1,nums.size()-1);
		}
	}

	return nums[p];
}
void test_lcof39()
{
	int num[] = { 4, 4,1, 2, 3, 2, 2, 2, 2};
	vector<int> nums(num,num+9);

	printf("%d\r\n",majorityElement(nums));
	printf("%d\r\n",majorityElement2(nums));

}