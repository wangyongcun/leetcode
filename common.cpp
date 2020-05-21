#include "StdAfx.h"
#include "common.h"

void reverse(string& s,int b,int e)
{
	while(b<e)
	{
		char t = s[b];
		s[b] = s[e];
		s[e] = t;

		++b;
		--e;
	}
}
