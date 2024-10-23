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
    int lvlSum[100000];

    void CalculateLvlSum(TreeNode* curr, int lvl = 0) {
        if (!curr)
            return;        
        lvlSum[lvl] += curr->val;
        CalculateLvlSum(curr->left, lvl + 1);
        CalculateLvlSum(curr->right, lvl + 1);
    }

    void ModifyTree(TreeNode* curr, int lvl = 0) {
        if (!curr)
            return;    
        if (!curr->left && !curr->right)
            return;
        int leftVal = 0, rightVal = 0;
        if (curr->left)
            leftVal = curr->left->val;
        if (curr->right)
            rightVal = curr->right->val;
        int newVal = lvlSum[lvl + 1] - leftVal - rightVal;
        if (curr->left)
            curr->left->val = newVal;
        if (curr->right)
            curr->right->val = newVal;
        ModifyTree(curr->left, lvl + 1);
        ModifyTree(curr->right, lvl + 1);
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        CalculateLvlSum(root);
        root->val = 0;
        ModifyTree(root);
        return root;
    }
};

int main() {
    return 0;
}