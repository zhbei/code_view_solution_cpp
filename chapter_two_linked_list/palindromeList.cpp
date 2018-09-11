#include "List.h"
#include <stack>

bool isPalindrome(ListNode* list){
	if(list == NULL || list->next == NULL){
		return true;
	}

	stack<ListNode*> stk;
	ListNode* tmp = list;
	while(tmp != NULL){
		stk.push(tmp);
		tmp = tmp->next;
	}

	tmp = list;
	while(tmp != NULL){
		if(tmp->val != stk.top()->val){
			return false;
		}
		if(stk.top() == tmp || stk.top() == tmp->next){
			cout << "true" << endl;
			return true;
		}
		stk.pop();
		tmp = tmp->next;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	ListNode* list = initList({1,2,3,4,5,6,7,6,5,4,3,2,1});
	cout << isPalindrome(list) << endl;
	return 0;
}