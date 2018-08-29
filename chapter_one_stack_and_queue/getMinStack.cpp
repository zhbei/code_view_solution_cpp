#include <stack>
#include <iostream>

using namespace std;

template <class T>
class MinStack{
private:
	stack<T> val,min;
public:
	T getMin(){
		if(!min.empty()){
			return min.top();
		}
		throw 0;
	}
	void pop(){
		if(val.empty()){
			throw 0;
		}
		val.pop();
		min.pop();
	}

	void push(T v){
		val.push(v);
		if(min.empty()){
			min.push(v);
			return;
		}
		if(min.top() < v){
			min.push(min.top());
		}else{
			min.push(v);
		}
	}
};

int main(){
	MinStack<char> ms;
	ms.push(6);
	cout << ms.getMin() << endl;
	ms.push(5);
	cout << ms.getMin() << endl;
	ms.push(3);
	cout << ms.getMin() << endl;
	ms.push(4);
	cout << ms.getMin() << endl;
	ms.push(2);
	cout << ms.getMin() << endl;

	return 0;
}