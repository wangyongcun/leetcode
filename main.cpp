#include "stdafx.h"
#include "quick_sort.h"
#include "merg_sort.h"
#include "lcof39_majorityElement.h"
//using namespace quick_sort;
#include "lcof11_xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof.h"
#include "lcof58_zuo-xuan-zhuan-zi-fu-chuan-lcof.h"
#include "lcof58-2_fan-zhuan-dan-ci-shun-xu-lcof.h"
#include "lcof60.h"
#include "lcof29.h"
#include "lcof30.h"
#include "lcof31.h"
#include "lcof33.h"
#include "lcof38.h"
#include "lcof45.h"
#include "leet43.h"

#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp(const void* a, const void* b) //qsort库要求参数const
{
	return strcmp((char*)a, (char*)b); //字典序从小到大
	//return strcmp((char *)b,(char *)a) ; //字典序从大到小
}

void main()
{

	test_leet43();
	test_lcof45();
	test_lcof38();
	test_lcof33();
	test_lcof31();
	test_lcof30();
	test_lcof29();

	test_lcof60();
	test_lcof58_2();
	return;
	test_lcof58();
	return;
	test_lcof11();
	return;
	test_lcof39();
	return ;
	test_ms(0,0);
	test_qs(0,0);
}