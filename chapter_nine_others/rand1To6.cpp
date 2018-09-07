#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int rand01p(){
	int p = 83;
	return (1 + rand()%100) > p ? 0 : 1;
}
int rand0To1(){
	int num = rand01p();
	while(num == rand01p()){
		num = rand01p();
	}
	return num;
}
int rand0To3(){
	return rand0To1() * 2 + rand0To1();
}
int rand1To6(){
	int r = rand0To3() * 4 + rand0To3();
	while(r > 11){
		r = rand0To3() * 4 + rand0To3();
	}
	return r%6 + 1;
}


int main(int argc, char const *argv[])
{
	vector<int> nums(8,0);
	for(int i = 0; i < 1000000; ++i){
		++nums[rand1To6()];
	}

	for(int i = 1; i < 8; ++i){
		cout << double(nums[i])/double(1000000) << endl;
	}
	return 0;
}