#include <iostream>

using namespace std;

int gcdCore(int a,int b){
	return b == 0 ? a : gcdCore(b,a%b);
}
int gcd(int a,int b){
	if(a < b){
		swap(a,b);
	}
	if(b == 0){
		return a;
	}
	return gcdCore(a,b);
}



int main(int argc, char const *argv[])
{
	int a,b;
	while(true){
		cout << "Please input two number or crtl + c :";
		cin >> a >> b;
		cout << "The gcd(" << a << "," << b << ") = " << gcd(a,b) << endl;
	}
	return 0;
}