#include <iostream>
#include "List.h"
using namespace std;


int Josephus(ListNode *list,const unsigned int k){
	if(k == 0){
		throw -1;
	}
	unsigned int count = 0;
	while(list->next != list){
		++count;
		if(count == k){
			list->val = list->next->val;
			ListNode *del = list->next;
			list->next = del->next;
			delete del;
			count = 0;
		}else{
			list = list->next;
		}
	}
	return list->val;
}
//old = (new + k - 1)%n + 1
//new is the ID of people after kill someone
//old is the ID of people befor kill someone
// n is the number of people befor kill someone
// k is 
//the last round when only one people survie the ID must be 1 
int JosephusOpti(ListNode *list,const unsigned int k){
	int len = 1;
	ListNode* tmp = list->next;
	while(tmp != list){
		++len;
		tmp = tmp->next;
	}
	int live = 1;
	int num = 2;
	while(num != len+1){
		live = (live + k - 1) % num + 1;
		++num;
	}
	while(live != 1){
		--live;
		list = list->next;
	}

	return list->val;
}

int main(int argc, char const *argv[])
{
	ListNode *head = initList({1,2,3,4,5,6,7,8,9});
	ListNode *last = head;
	while(last->next != NULL){
		last = last->next;
	}
	last->next = head;
	int kill = 5;
	cout << Josephus(head,kill) << endl;	
	ListNode *head2 = initList({1,2,3,4,5,6,7,8,9});
	ListNode *last2 = head2;
	while(last2->next != NULL){
		last2 = last2->next;
	}
	last2->next = head2;

	cout << JosephusOpti(head2,kill) << endl;
	return 0;
}