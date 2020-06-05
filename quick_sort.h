#include "stdafx.h"

int partion(int* nums,int b,int e)
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

void qs(int* nums, int b, int e)
{
	if (b >= e)
	{
		return;
	}

	int p = partion(nums, b, e);

	qs(nums, b, p);
	qs(nums, p + 1, e);
}

int test_qs_2()
{
	int nums[100] = { 9,8,2,6,4,5,3,1,0,7 };
	
	qs(nums, 0, 9);

	for (int i = 0; i <= 9; ++i)
	{
		printf("%d", nums[i]);
	}
	return 0;
}
