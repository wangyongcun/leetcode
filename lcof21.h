
#include <vector>
using namespace std;
vector<int> exchange(vector<int>& nums) {
	int i = 0;
	int j = nums.size() - 1;
	while(i < j){
		if (nums[i] % 2 == 1)
			++i;
		else if (nums[j] % 2 == 0)
			--j;

		if (nums[i] % 2 == 0 && nums[j] % 2 == 1){
			swap(nums[i], nums[j]);
			++i; --j;
		}
	}

}