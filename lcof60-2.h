/// https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
#include <math.h>
vector<double> twoSum(int n) {
	vector<double> t;

	int* p = new int[n * 6 + 1];
	memset(p,0, sizeof(int) * (6 * n + 1));
	int nTotal = pow(double(6), n);

	printf("%d", nTotal);

	for (int i = 1; i <= 6; ++i)
	{
		p[i] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{
		p[i - 1] = 1;

		for (int j = 6 * i; j > i; --j)
		{
			int t = 0;
			for (int k = 1; k <= 6; ++k)
			{
				if (j - k >= (i-1))
					t += p[j - k];
			}
			p[j] = t;
		}
	}

	p[n] = 1;

	for (int i = n; i <= n * 6; ++i)
	{
		t.push_back(float(p[i]) / nTotal);
	}

	return t;
}

void test_lcof60()
{
	twoSum(5);
}