#include <iostream>
#include <stack>
using namespace std;

int getAndRemoveLast(stack<int> &stk){
	int tmp = stk.top();
	stk.pop();
	if(stk.empty()){
		return tmp;
	}else{
		int last = getAndRemoveLast(stk);
		stk.push(tmp);
		return last;
	}
}
void reverseStack(stack<int> &stk){
	if(stk.empty()){
		return;
	}
	int tmp = getAndRemoveLast(stk);
	reverseStack(stk);
	stk.push(tmp);
}

int main(int argc, char const *argv[])
{
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	stk.push(6);
	reverseStack(stk);
	while(!stk.empty()){
		cout << stk.top() << endl;
		stk.pop();
	}
	return 0;
}