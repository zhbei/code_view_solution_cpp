#include <iostream>
#include <vector>
using namespace std;
//leetcode 85
int maximalRectangle(vector<vector<char>>& mat) {
    int row = mat.size();
    if(row == 0)return 0;

    int col = mat[0].size();
    if(col == 0)return 0;

    vector<int> height(col+1,0);
    int maxArea = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            height[j] = mat[i][j] != '0' ? height[j] + 1 : 0;
        }
        stack<int> simpStk;
        simpStk.push(-1);
        for(int k = 0; k <= col; ++k){
            while(simpStk.top() != -1 && height[simpStk.top()] >= height[k]){
            	int h = simpStk.top();
                simpStk.pop();
            	maxArea = max(maxArea,(k - simpStk.top()-1)*height[h]);
            }
            simpStk.push(k);
        }
    }
    return maxArea;
}
