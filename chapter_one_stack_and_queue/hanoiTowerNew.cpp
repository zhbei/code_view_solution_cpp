#include <iostream>
#include <string>
using namespace std;

void hanoi(int n,string left, string mid, string right,string from, string to){
	if(n == 1){
		if(from == mid || to == mid)
			cout << "Move " << n << " from " << from << " to " << to << endl;
		else{
			cout << "Move " << n << " from " << from << " to " << mid << endl;
			cout << "Move " << n << " from " << mid << " to " << to << endl;
		}
		return;
	}
	if((left == from && right == to) || (left == to && right == from)){
		hanoi(n-1,left,mid,right,from,mid);
		hanoi(n-1,left,mid,right,mid,to);
		cout << "Move " << n << " from " << from << " to " << mid << endl;
		hanoi(n-1,left,mid,right,to,mid);
		hanoi(n-1,left,mid,right,mid,from);
		cout << "Move " << n << " from " << mid << " to " << to << endl;
		hanoi(n-1,left,mid,right,from,mid);
		hanoi(n-1,left,mid,right,mid,to);
		return;
	}
	string tmp;
	if((mid == from && right == to) || (mid == to && right == from)){
		tmp = left;
	}		
	if((left == from && mid == to) || (left == to && mid == from)){
		tmp = right;
	}
	if(mid == from){
		hanoi(n-1,left,mid,right,from,tmp);
		cout << "Move " << n << " from " << from << " to " << to << endl;
		hanoi(n-1,left,mid,right,tmp,mid);
		hanoi(n-1,left,mid,right,mid,to);
	}else{
		hanoi(n-1,left,mid,right,from,mid);
		hanoi(n-1,left,mid,right,mid,tmp);
		cout << "Move " << n << " from " << from << " to " << to << endl;
		hanoi(n-1,left,mid,right,tmp,to);
	}

}



int main(int argc, char const *argv[])
{
	string left = "left", right = "right", mid = "mid";
	hanoi(3,left,mid,right,left,right);
	return 0;
}

