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
    void RemoveNodes(TreeNode*& curr, int target){
        if (!curr)
            return;
        RemoveNodes(curr->left, target);
        RemoveNodes(curr->right, target);
        if (!curr->left && !curr->right && curr->val == target){
            curr = nullptr;
            delete(curr);
        }
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        RemoveNodes(root, target);
        return root;
    }
};

int main(){
    return 0;
}