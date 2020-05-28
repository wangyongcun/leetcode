#pragma once
///https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
#include <list>
using namespace std;

int lastRemaining(int n, int m) {

	list<int> l;
	for (int i=0;i<n;++i)//bug ,used m but right is n
	{
		l.push_back(i);
	}
	
	int count = 1;
	list<int>::iterator it = l.begin();
	while (l.size()>1)
	{
		if (count == m){
			it = l.erase(it);
			count = 1;
		}
		else
		{
			if (it == l.end())///bug after erase it may be at l.end()
				it = l.begin();
			++it;
			count++;
			if (it == l.end())
				it = l.begin();
		}
	}
	
	return *(l.begin());
}

void test_lcof62()
{
	lastRemaining(70866, 116922);
	lastRemaining(5, 3);
}