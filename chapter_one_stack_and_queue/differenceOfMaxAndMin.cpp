#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int getNumber(const vector<int> &nums,const int diff){
	int size = nums.size();
	if(size == 0)return 0;

	int ans = 0;

	deque<int> maxD,minD;

	int i = 0,j = 0;
	while(i < size){
		while(j < size){
			while(!maxD.empty() && nums[maxD.back()] <= nums[j]){
				maxD.pop_back();
			}
			maxD.push_back(j);
			while(!minD.empty() && nums[minD.back()] >= nums[j]){
				minD.pop_back();
			}
			minD.push_back(j);

			++j;
			if(nums[maxD.front()] - nums[minD.front()] > diff){
				ans += j - i - 1;
				cout << j - i - 1 << endl;
				break;
			}
		}
		if(nums[maxD.front()] - nums[minD.front()] <= diff){
			ans += j - i;
			cout << j - i << endl;
			++i;
		}
		while(!maxD.empty() && !minD.empty() && (nums[maxD.front()] - nums[minD.front()]) > diff){
			if(maxD.front() == i){
				maxD.pop_front();
			}
			if(minD.front() == i){
				minD.pop_front();
			}
			++i;
		}
	}
	return ans;
}

int validate(const vector<int> &nums,const int diff){
	int size = nums.size();
	if(size == 0)return 0;

	int ans = 0;
	for(int i = 0; i < size; ++i){
		for(int j = i; j < size; ++j){
			int minV = nums[j], maxV = nums[j];
			for(int k = i; k <= j; ++k){
				if(nums[k] > maxV){
					maxV = nums[k];
				}else if(nums[k] < minV){
					minV = nums[k];
				}
			}
			if(maxV - minV <= diff){
				++ans;
			}
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> arr{4,5,6,7,1,2,4,1,3,13,7};
	cout << "Ans should be : " << validate(arr,10) << endl;
	cout << "My ans is : " << getNumber(arr,10) << endl;
	return 0;
}