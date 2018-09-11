#include <iostream>

#include "List.h"

using namespace std;

ListNode* deleteMid(ListNode *list){
	ListNode *fast = list, *slow = list;
	if(list == NULL){
		return NULL;
	}
	if(list->next == NULL){
		delete list;
		return NULL;
	}

	while(fast->next != NULL && fast->next->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	slow->val = slow->next->val;
	fast = slow->next;
	slow->next = fast->next;
	delete fast;//free the mem
	return list;
}

int main(int argc, char const *argv[])
{
	ListNode * list = initList({1,2,3,4,5});
	list = deleteMid(list);
	ListNode *tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	list = deleteMid(list);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	list = deleteMid(list);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	list = deleteMid(list);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	list = deleteMid(list);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	list = deleteMid(list);
	tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	return 0;
}