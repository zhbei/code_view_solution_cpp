#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int rand5(){
	return 1 + rand()%5;
}

int rand7(){
	int r = (rand5() - 1) * 5 + rand5() - 1;
	while(r > 20){
		r = (rand5() - 1) * 5 + rand5() - 1;
	}
	return r%7 + 1;
}


int main(int argc, char const *argv[])
{
	vector<int> nums(8,0);
	for(int i = 0; i < 1000000; ++i){
		++nums[rand7()];
	}

	for(int i = 1; i < 8; ++i){
		cout << double(nums[i])/double(1000000) << endl;
	}
	return 0;
}