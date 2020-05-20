#include "stdafx.h"



void merge(int* nums,int b,int m,int e)
{
	if(b == e)
		return;

	int* tmp = new int[e-b+1];
	int i=0;
	int om = m;
	int ob = b;

	m = m+1;
	while(b <= om && m <=e )
	{
		if (nums[m] < nums[b] )
		{
			tmp[i++] = nums[m++];
		}
		else
		{
			tmp[i++] = nums[b++];
		}
	}

	while(b<=om)
	{
		tmp[i++] = nums[b++];
	}

	while(m<=e)
	{
		tmp[i++] = nums[m++];
	}

	for(int i=0;i<= e-b;++i)
	{
		nums[ob+i] = tmp[i];
	}

	delete [] tmp;
}

void ms(int* nums, int b, int e)
{
	if(nums == 0)
		return;

	if (b >= e)
	{
		return;
	}

	int m = (b+e)/2;
	ms(nums, b, m);
	ms(nums, m + 1, e);

	merge(nums,b,m,e);
}

int test_ms(int argc, _TCHAR* argv[])
{
	int nums[100] = { 9,8,2,6,4,5,3,1,0,7 };
	qs(nums, 0, 9);

	for (int i = 0; i <= 9; ++i)
	{
		printf("%d", nums[i]);
	}
	return 0;
}
