#include <iostream>

using namespace std;
void flod(int i,const int N, bool down){
	if(i > N){
		return;
	}

	flod(i+1,N,false);
	cout << (down == true ? " down " : " up ") << endl;
	flod(i+1,N,true);
}

void foldPaper(int n){
	flod(1,n,true);
}
int main(int argc, char const *argv[])
{
	int n = 2;
	while(n){
		cin >> n;
		foldPaper(n);
		cout << endl;
	}
	return 0;
}