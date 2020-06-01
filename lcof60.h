/// https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
#include <math.h>
vector<double> twoSum(int n) {
	vector<double> t;

	int* p = new int[n * 6 + 1];
	memset(p,0, sizeof(int) * (6 * n + 1));
	int nTotal = pow(double(6), n);

	pro(0,1,n,p);
	printf("%d", nTotal);

	for (int i = n; i <= n * 6; ++i)
	{
		t.push_back(float(p[i]) / nTotal);
	}

	return t;
}

void pro(int curSum,int curDice,int maxDice,int* p)
{
	for(int i=1;i<=6;++i){
		curSum += i;

		if (curDice == maxDice)
		{
			p[curSum] ++;
		}
		else{
			pro(curSum,curDice+1,maxDice,p);
		}
	}

}

void test_lcof60()
{
	twoSum(5);
}