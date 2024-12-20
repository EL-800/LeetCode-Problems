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
    vector<TreeNode*> lastVal;

    void TransverseTree(TreeNode* left, TreeNode *right, int level = 0) {
        if (!left || !right)
            return;        
        if (level % 2 == 0)
            swap(left->val, right->val);
        TransverseTree(left->left, right->right, level + 1);
        TransverseTree(left->right, right->left, level + 1);        
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {        
        TransverseTree(root->left, root->right);
        return root;
    }
};

int main() {
    return 0;
}