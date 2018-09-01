#include <iostream>
#include <vector>
#include <deque>

using namespace std;
//store the index
vector<int> windowsMax(const vector<int> &nums,const int k){
	int size = nums.size();
	vector<int> ans;
	if(size == 0 || k > size){
		return ans;
	}

	deque<int> window;
	//this loop can be merge into the next loop, but I do not konw which way is more efficient
	for(int i = 0; i < k; ++i){
		while(!window.empty() && nums[window.back()] < nums[i]){
			window.pop_back();
		}
		window.push_back(i);
	}
	for(int i = k; i < size; ++i){
		ans.push_back(nums[window.front()]);
		if(window.front() == i - k){
			window.pop_front();
		}
		while(!window.empty() && nums[window.back()] < nums[i]){
			window.pop_back();
		}
		window.push_back(i);	
	}
	return ans;
}
//store the value
vector<int> windowsMax2(const vector<int> &nums,const int k){
	int size = nums.size();
	vector<int> ans;
	if(size == 0 || k > size){
		return ans;
	}

	deque<int> window;
	for(int i = 0; i < k; ++i){
		while(!window.empty() && window.back() < nums[i]){
			window.pop_back();
		}
		window.push_back(nums[i]);
	}
	for(int i = k; i < size; ++i){
		ans.push_back(window.front());
		if(window.front() == nums[i - k]){
			window.pop_front();
		}
		while(!window.empty() && window.back() < nums[i]){
			window.pop_back();
		}
		window.push_back(nums[i]);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	vector<int> ans;
	vector<int> nums{4,3,5,4,3,3,6,6,7,8,1,2};
	ans = windowsMax2(nums,3);
	for(int i : ans){
		cout << i << '\t';
	}	
	cout << endl;
	ans = windowsMax(nums,3);
	for(int i : ans){
		cout << i << '\t';
	}
	cout << endl;
	return 0;
}