#include <vector>
#include <iostream>

using namespace std;

int maxAbs(const vector<int> &nums){
	int size = nums.size();
	if(size == 0 || size == 1)return 0;
	int max = INT_MIN;
	for(int i = 0; i < size; ++i){
		if(nums[i] > max){
			max = nums[i];
		}
	}
	return abs(max-min(nums[0],nums[size-1]));
}


int main(int argc, char const *argv[])
{
	vector<int> nums{11,3,4,5,7,119,2,4,5,6,111,1,0,12};
	cout << maxAbs(nums) << endl;
	return 0;
}