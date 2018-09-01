#include <iostream>
#include <string>
using namespace std;

void hanoi(int n,string left, string mid, string right,string from, string to){
	if(n == 1){
		cout << "Move " << n << " from " << from << " to " << to << endl;
		return;
	}
	string tmp;
	if((left == from && right == to) || (left == to && right == from)){
		tmp = mid;
	}
	if((mid == from && right == to) || (mid == to && right == from)){
		tmp = left;
	}		
	if((left == from && mid == to) || (left == to && mid == from)){
		tmp = right;
	}
	hanoi(n-1,left,mid,right,from,tmp);
	cout << "Move " << n << " from " << from << " to " << to << endl;
	hanoi(n-1,left,mid,right,tmp,to);
}



int main(int argc, char const *argv[])
{
	string left = "left", right = "right", mid = "mid";
	hanoi(3,left,mid,right,left,right);
	return 0;
}

