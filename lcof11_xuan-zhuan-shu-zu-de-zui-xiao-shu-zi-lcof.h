
int minArray(vector<int>& nums) {
	if (nums.size() == 0)
	{
		return -1;
	}

	if(nums.size() == 1)
	{
		return nums[0];
	}

	int p1 = 0;
	int p2 = nums.size()-1;
	int m = 0;//非常关键的小技巧,正常排序的数组也是一个特殊的旋转数组

	while (nums[p1] >= nums[p2])//关键点,如果用p2-p1 > 1作为结束条件,对于已经排序的数组会永远跳不出循环
	{
		if(p2-p1==1)//夹逼,把p1,p2永远把缝夹在中间,直到p1-p2中间没有内容,p2就是那个最小值
			///这种思路比思路2=>判断[p1,m][m+1,p2]是否递增简单些
			///思路2中判断单调递增需要考虑多个元素递增和单个元素,如果两边都递增,m+1是最小值

		{
			m = p2;
			break;
		}

		m = (p1+p2)/2;
		if (nums[m] >= nums[p1] )
		{
			p1 = m;
		}
		else if( nums[m] <= nums[p2] )
		{
			p2 = m;
		}
	}

	return nums[m];
}

void test_lcof11()
{
	int num[] = {3,4,5,1,2};
	vector<int> nums(num,num+5);
	printf("%d",minArray(nums));

	int num2[] = {3,1,3};
	vector<int> nums2(num2,num2+3);
	printf("%d",minArray(nums2));
}