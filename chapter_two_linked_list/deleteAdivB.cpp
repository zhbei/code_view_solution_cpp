#include <iostream>
#include <cmath>

#include "List.h"

using namespace std;

ListNode* deleteAdivB(ListNode *list,const unsigned int A, const unsigned int B){
	if(B == 0){
		cerr << "Divide by zero" << endl;
		throw 0;
	}
	if(A > B || A == 0 || list == NULL){
		return list;
	}
	int len = 0;
	ListNode *tmp = list;
	while(tmp){
		++len;
		tmp = tmp->next;
	}

	int del = ceil((double(A)/B) * len);
	tmp = list;
	if(del == 1){
		tmp = list->next;
		delete list;
		return tmp;
	}
	while(del != 2){
		--del;
		tmp = tmp->next;
	}
	ListNode *to = tmp->next;
	tmp->next = to->next;
	delete to;
	return list;
}

int main(int argc, char const *argv[])
{
	ListNode * list = initList({1,2,3,4,5});
	list = deleteAdivB(list,0,10);
	ListNode *tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	list = deleteAdivB(list,5,7);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;

	list = deleteAdivB(list,5,7);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	list = deleteAdivB(list,5,7);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	list = deleteAdivB(list,5,7);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	list = deleteAdivB(list,5,7);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	return 0;
}