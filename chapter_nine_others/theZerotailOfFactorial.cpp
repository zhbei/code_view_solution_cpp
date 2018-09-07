#include <iostream>
using namespace std;

int factorial(int n){
	if(n == 0)return 0;
	int ans = 0;
	while(n != 0){
		ans += n/5;
		n /= 5;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n = 0;
	while(true){
		cout << "Please input a number : ";
		cin >> n;
		if(n < 0){
			cout << "Invalid input!" << endl;
		}else{
			cout << "The tail zero of the n! is : " << factorial(n) << endl;
		}
	}
	return 0;
}