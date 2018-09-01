#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

TreeNode* buildTree(const vector<int> &nums){
	int size = nums.size();
	if(size == 0)return NULL;

	vector<TreeNode*> allNodes;
	for(int i : nums){
		allNodes.push_back(new TreeNode(i));
	}

	stack<int> simpStk;
	vector<int> left(size,-1),right(size,-1);
	simpStk.push(-1);
	for(int i = 0; i < size; ++i){
		while(simpStk.top() != -1 && nums[simpStk.top()] < nums[i]){
			simpStk.pop();
		}
		left[i] = simpStk.top();
		simpStk.push(i);
	}
	stack<int> simpStk2;
	simpStk2.push(-1);
	for(int i = size-1; i >= 0; --i){
		while(simpStk2.top() != -1 && nums[simpStk2.top()] < nums[i]){
			simpStk2.pop();
		}
		right[i] = simpStk2.top();
		simpStk2.push(i);
	}
	TreeNode *ans;
	for(int i = 0; i < size; ++i){
		if(left[i] == -1 && right[i] == -1){
			ans = allNodes[i];
		}else if(left[i] == -1){
			allNodes[right[i]]->left = allNodes[i];
		}else if(right[i] == -1){
			allNodes[left[i]]->right = allNodes[i];
		}else{
			if(nums[left[i]] < nums[right[i]]){
				allNodes[left[i]]->right = allNodes[i];
			}else{
				allNodes[right[i]]->left = allNodes[i];
			}
		}
	}
	return ans;
}

void preOrder(TreeNode *root){
	if(root == NULL)return ;
	cout << root->val << endl;
	preOrder(root->left);
	preOrder(root->right);
}

int main(int argc, char const *argv[])
{
	vector<int> arr{4,3,5,2,6,1,7,9};
	TreeNode * ans = buildTree(arr);
	preOrder(ans);
	return 0;
}

