#include <iostream>
#include "List.h"


ListNode* reverse(ListNode *list, const unsigned int from, const unsigned int to){
	if(list == NULL)return NULL;


	unsigned int i = 1;
	//the List node which is before the from
	ListNode *last = NULL;

	ListNode *tmp = list;
	while(i < from && tmp != NULL){
		last = tmp;
		++i;
		tmp = tmp->next;
	}
	if(i < from){
		return list;
	}
	//the reversed list tail
	ListNode *tail = tmp;
	
	//the tmp list var for reverse
	ListNode* pre = NULL, *next = NULL;
	while(i <= to && tmp != NULL){
		++i;
		next = tmp->next;
		tmp->next = pre;
		pre = tmp;
		tmp = next;
	}
	//when from == 1, the last node is NULL
	if(last != NULL){
		last->next = pre;
		pre = list;
	}
	tail->next = tmp;
	return pre;
}

int main(int argc, char const *argv[])
{
	ListNode *list = initList({1,2,3,4,5,6,7,8,9});
	print(list);
	list = reverse(list,2,15);
	print(list);

	return 0;
}