/// https://leetcode-cn.com/problems/chou-shu-lcof/submissions/
#pragma once
#include "stdlib.h"
#include <iostream>
#define min(a,b) (((a) < (b)) ? (a) : (b))

int nthUglyNumber(int n) {
	if (n < 0)
		return 0;

	int N[2000] = { 0 };
	memset(N, 2000, sizeof(int));

	int nex = 0;
	int x2 = 0;
	int x3 = 0;
	int x5 = 0;
	N[nex] = 1;

	while (nex < n) {

		int min = min(min(N[x2] * 2, N[x3] * 3), N[x5] * 5);
		N[++nex] = min;
		if (min == N[x2] * 2) x2++;
		if (min == N[x3] * 3) x3++;
		if (min == N[x5] * 5) x5++;
	}

	return N[n - 1];
}

void test_lcof49()
{
	int n = nthUglyNumber(1);
	n = nthUglyNumber(100);
}