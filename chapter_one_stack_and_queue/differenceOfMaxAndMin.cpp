#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int getNumber(const vector<int> &nums,const int diff){
	int size = nums.size();
	if(size == 0)return 0;

	int ans = 0;

	deque<int> maxD,minD;
	vector<bool> visited(size,false);
	int i = 0,j = 0;
	while(i < size){
		//there are some question
		// some index maybe add to minD or maxD more than onece 
		// how can ensure this situation will not be encour mistake??
		//for fix this question I new a visited array to record which index is dealed
		while(j < size){
			if(visited[j] == false){
				while(!maxD.empty() && nums[maxD.back()] <= nums[j]){
					maxD.pop_back();
				}
				maxD.push_back(j);
				while(!minD.empty() && nums[minD.back()] >= nums[j]){
					minD.pop_back();
				}
				minD.push_back(j);
				visited[j] = true;
			}
			if(nums[maxD.front()] - nums[minD.front()] > diff){
				break;
			}
			++j;
		}
		if(maxD.front() == i){
			maxD.pop_front();
		}
		if(minD.front() == i){
			minD.pop_front();
		}
		//if a[i...j] is vailid , then a[i+k...j] is also vailid
		//because when the i is plus some number, there are two situation 
		// 1. maxVal will be decrease or
		// 2. minVal will be increase 
		// In either case the difference of maxVal and minVal will be decrease
		ans += j - i;
		++i;
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
	vector<int> arr{1,2,3,4,1,1,2,1,3};
	int diff = 3;
	cout << "Ans should be : " << validate(arr,diff) << endl;
	cout << "My ans is : " << getNumber(arr,diff) << endl;
	return 0;
}