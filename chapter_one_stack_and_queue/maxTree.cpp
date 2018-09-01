#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	TreeNode *left, *right;
	int val;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};


