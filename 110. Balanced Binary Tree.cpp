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
    bool ans = true;

    int DFS(TreeNode *curr) {
        if (!curr)
            return 0;               
        int leftLevel = DFS(curr->left);
        int rightLevel = DFS(curr->right);
        
        if (abs(leftLevel - rightLevel) >= 2)
            ans = false;

        return max(leftLevel, rightLevel) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        DFS(root);
        return ans;
    }
};

int main() {
    return 0;
}