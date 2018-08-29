#include <iostream>
#include <stack>

using namespace std;
template <class T>
class Queue{
private:
	stack<T> stk1, stk2;
public:
	T front(){
		if(!stk2.empty()){
			return stk2.top();
		}else if(!stk1.empty()){
			while(!stk1.empty()){
				stk2.push(stk1.top());
				stk1.pop();
			}
			return stk2.top();
		}else{
			throw 0;
		}
	}
	T pop_front(){
		if(!stk2.empty()){
			T t = stk2.top();
			stk2.pop();
			return t;
		}else if(!stk1.empty()){
			while(!stk1.empty()){
				stk2.push(stk1.top());
				stk1.pop();
			}
			T t = stk2.top();
			stk2.pop();
			return t;
		}else{
			throw 0;
		}
	}
	void push_back(T v){
		stk1.push(v);
	}
};

int main(){
	Queue<int> que;
	que.push_back(1);
	cout << que.pop_front() << endl;
	que.push_back(2);
	que.push_back(3);
	que.push_back(4);
	cout << que.pop_front() << endl;
	que.push_back(5);
	cout << que.pop_front() << endl;
	que.push_back(6);
	cout << que.pop_front() << endl;
	que.push_back(7);
	cout << que.pop_front() << endl;
	cout << que.pop_front() << endl;
	cout << que.pop_front() << endl;
	return 0;
}
