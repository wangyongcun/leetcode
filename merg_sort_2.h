#include "stdafx.h"



void merge2(int* nums,int b,int m,int e)
{
	int* tmp = new int[e - b + 1];

	int p1 = b;
	int p2 = m+1;

	int indeTmp = 0;
	while (p1 <= m && p2 <= e){

		if (nums[p1] <= nums[p2])
			tmp[indeTmp++] = nums[p1++];
		else
			tmp[indeTmp++] = nums[p2++];
		//printf("%d\n", tmp[indeTmp-1]);
	}

	while (p1<=m)		
		tmp[indeTmp++] = nums[p1++];

	while (p2 <= e)
		tmp[indeTmp++] = nums[p2++];

	for (int i=0;i<=e-b;++i)
		nums[b+i] = tmp[i];

	delete[] tmp;
}

void ms2(int* nums, int b, int e)
{
	if (e-b < 1){
		return;
	}

	int mid = (b + e) / 2;
	ms2(nums, b, mid);
	ms2(nums, mid+1, e);

 	merge2(nums, b, mid, e);
}

int test_ms_2()
{
	int nums[100] = { 9,8,2,6,4,5,3,1,0,7 };
	ms2(nums, 0, 9);

	for (int i = 0; i <= 9; ++i)
	{
		printf("%d", nums[i]);
	}
	return 0;
}
