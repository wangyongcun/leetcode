#include "stdafx.h"
#include <algorithm>
using namespace std;

void qs2(int* nums, int b, int e)
{
	int ob = b;
	int oe = e;

	if (e - b <= 0)
		return ;

	int pivote = nums[(b + e) / 2];

	while (b < e){
		if (nums[b]<=pivote) {
			++b;
		}
		else if(nums[e] > pivote ) {
			--e;
		}
		else
		{
			swap(nums[b], nums[e]);
		}
	}

	int m = b;
	if (nums[b] > pivote){
		m--;
	}

	qs2(nums, ob, m);
	qs2(nums, m+1, e);
}

int test_qs(int argc, _TCHAR* argv[])
{
	int nums[100] = { 9,8,2,6,4,5,3,1,0,7 };
	
	qs2(nums, 0, 9);

	for (int i = 0; i <= 9; ++i)
	{
		printf("%d", nums[i]);
	}
	return 0;
}
