#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int Sum(TreeNode* curr, int currSum = 0) {
        if (!curr)
            return 0;
        currSum = currSum * 10 + curr->val;
        if (!curr->left && !curr->right)
            return currSum;
        return Sum(curr->left, currSum) + Sum(curr->right, currSum);
    }

public:
    int sumNumbers(TreeNode* root) {
        return Sum(root);
    }
};

int main(){
    return 0;
}