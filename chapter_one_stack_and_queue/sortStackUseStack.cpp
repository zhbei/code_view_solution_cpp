#include <iostream>
#include <stack>

using namespace std;
//default compare fun is less than
void sort(stack<int> &stk,bool (*foo)(int a,int b)=[](int a,int b){return a < b;}){
	stack<int> tmp;
	if(stk.empty())return;
	tmp.push(stk.top());
	stk.pop();
	while(!stk.empty()){
		int t = stk.top();
		stk.pop();
		while(!tmp.empty() && !foo(tmp.top(),t)){
			stk.push(tmp.top());
			tmp.pop();
		}
		tmp.push(t);
	}
	swap(tmp,stk);
}
int main(){
	stack<int> stk;
	stk.push(6);
	stk.push(1);
	stk.push(2);
	stk.push(5);
	stk.push(3);
	stk.push(4);
	sort(stk);
	while(!stk.empty()){
		cout << stk.top() << endl;
		stk.pop();
	}
	return 0;
}
