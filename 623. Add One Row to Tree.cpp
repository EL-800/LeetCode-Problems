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
    int val, depth;
    void AddRow(TreeNode*& curr, int level = 1) {
        if (!curr)
            return;
        if (level == depth - 1) {
            curr->left = new TreeNode(val, curr->left, NULL);
            curr->right = new TreeNode(val, NULL, curr->right);
            return;
        }        
        AddRow(curr->left, level + 1);
        AddRow(curr->right, level + 1);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        this->val = val;
        this->depth = depth;
        if (depth > 1)
            AddRow(root);
        else
            root = new TreeNode(val, root, NULL);
        return root;
    }
};

int main(){
    return 0;
}