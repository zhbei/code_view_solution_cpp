#include "List.h"

#include <iostream>

using namespace std;

ListNode* deleteKth(ListNode *list,const int k){
	if(list == NULL || k < 1)return NULL;
	int i = 0;
	ListNode *dump = new ListNode(-1);
	dump->next = list;
	ListNode *last = dump;
	while(i < k && last != NULL){
		++i;
		last = last->next;
	}

	if(i < k){
		return NULL;
	}

	ListNode *first = dump;
	while(last->next != NULL){
		first = first->next;
		last = last->next;
	}
	last = first->next;
	first->next = last->next;
	delete last;
	list = dump->next;
	delete dump;

	return list;
}

int main(int argc, char const *argv[])
{
	ListNode *list = initList({1,2,3,4,5,6,7,8,9});
	ListNode *tmp = list;
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	tmp = deleteKth(list,1);
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	tmp = deleteKth(list,3);
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	tmp = deleteKth(list,7);
	while(tmp){
		cout << tmp->val << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	return 0;
}