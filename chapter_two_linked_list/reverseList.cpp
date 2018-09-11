#include "List.h"

#include <iostream>

using namespace std;

ListNode* reverse(ListNode *list){
	if(list == NULL){
		return NULL;
	}

	ListNode *next = NULL, *pre = NULL;
	while(list != NULL){
		next = list->next;
		list->next = pre;
		pre = list;
		list = next;
	}
	return pre;
}

DoubleList* reverse(DoubleList *list){
	if(list == NULL){
		return NULL;
	}


	DoubleList *next = NULL, *pre = NULL;
	while(list != NULL){
		next = list->next;
		list->next = pre;
		pre = list;
		list->pre = next;
		list = next;
	}
	
	return pre;
}

int main(int argc, char const *argv[])
{
	ListNode *list = initList({1,2,3,4,5,6,7,8,9});
	DoubleList *dlist = initDoubleList({1,2,3,4,5,6,7,8,9});

	cout << "Init : " << endl;
	print(list);
	list = reverse(list);
	cout << "After Reverse : "<< endl;
	print(list);

	cout << "Init : "<< endl;
	print(dlist);
	dlist = reverse(dlist);
	cout << "After Reverse : "<< endl;
	print(dlist);
	return 0;
}