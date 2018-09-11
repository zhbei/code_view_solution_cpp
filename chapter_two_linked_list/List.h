#include <iostream>
#include <vector>
using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v):val(v),next(NULL){}
};
struct DoubleList
{
	int val;
	DoubleList *next,*pre;
	DoubleList(int v):val(v),next(NULL),pre(NULL){}
};

ListNode* initList(const vector<int> &nums){
	int size = nums.size();
	if(size == 0)return NULL;

	ListNode *ans = new ListNode(nums[0]);
	ListNode *pre = ans;
	for(int i = 1; i < size; ++i){
		pre->next = new ListNode(nums[i]);
		pre = pre->next;
	}
	return ans;
}

DoubleList* initDoubleList(const vector<int> &nums){
	int size = nums.size();
	if(size == 0)return NULL;

	DoubleList *ans = new DoubleList(nums[0]);
	DoubleList *pre = ans;
	for(int i = 1; i < size; ++i){
		DoubleList *t = new DoubleList(nums[i]);

		pre->next = t;
		t->pre = pre;

		pre = pre->next;
	}
	return ans;
}

void print(ListNode *list){
	while(list){
		cout << list->val << '\t';
		list = list->next;
	}
	cout << endl;
}

void print(DoubleList *list){
	DoubleList *pre;
	while(list){
		cout << list->val << '\t';
		pre = list;
		list = list->next;
	}
	cout << endl;
	while(pre){
		cout << pre->val << '\t';
		pre = pre->pre;
	}
	cout << endl;
}