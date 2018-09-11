#include "List.h"

#include <iostream>
using namespace std;


void printComm(const ListNode *list1,const ListNode *list2){
	while(list1 != NULL && list2 != NULL){
		if(list1->val == list2->val){
			cout << list1->val << '\t';
			list1 = list1->next;
			list2 = list2->next;
		}else if(list1->val > list2->val){
			list2 = list2->next;
		}else{
			list1 = list1->next;
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	ListNode *list1 = initList({1,2,3,4,5,6,7,8,9,10,11});
	ListNode *list2 = initList({1,3,5,7,8,9,10,12,14,15,16,18});

	cout << "The common part is : ";
	printComm(list1,list2);
	cout << endl;
	return 0;
}