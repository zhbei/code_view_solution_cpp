#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

unsigned int rand(unsigned int n){
	return rand()%n;
}

vector<int> getNumsRand(const unsigned int k, const unsigned int max){
	vector<int> ans(k,0);
	if(max < 1 || k < 1){
		ans.clear();
		return ans;
	}
	for(size_t i = 0; i < k; ++i){
		ans[i] = i + 1;
	}

	for(size_t i = k; i < max; ++i){
		if(rand(i+1) < k){
			ans[rand(k)] = i + 1;
		}
	}
	return ans;
}



int main(int argc, char const *argv[])
{
	srand(time(NULL));
	vector<int> ans = getNumsRand(10,1000);
	for(int i : ans){
		cout << i << endl;
	}

	return 0;
}