
int minArray(vector<int>& nums) {
	if (nums.size() == 0)
	{
		return -1;
	}

	if(nums.size() == 1)
	{
		return nums[0];
	}

	int p1 = 0;
	int p2 = nums.size()-1;
	int m = 0;//�ǳ��ؼ���С����,�������������Ҳ��һ���������ת����

	while (nums[p1] >= nums[p2])//�ؼ���,�����p2-p1 > 1��Ϊ��������,�����Ѿ�������������Զ������ѭ��
	{
		if(p2-p1==1)//�б�,��p1,p2��Զ�ѷ�����м�,ֱ��p1-p2�м�û������,p2�����Ǹ���Сֵ
			///����˼·��˼·2=>�ж�[p1,m][m+1,p2]�Ƿ������Щ
			///˼·2���жϵ���������Ҫ���Ƕ��Ԫ�ص����͵���Ԫ��,������߶�����,m+1����Сֵ

		{
			m = p2;
			break;
		}

		m = (p1+p2)/2;
		if (nums[m] >= nums[p1] )
		{
			p1 = m;
		}
		else if( nums[m] <= nums[p2] )
		{
			p2 = m;
		}
	}

	return nums[m];
}

void test_lcof11()
{
	int num[] = {3,4,5,1,2};
	vector<int> nums(num,num+5);
	printf("%d",minArray(nums));

	int num2[] = {3,1,3};
	vector<int> nums2(num2,num2+3);
	printf("%d",minArray(nums2));
}