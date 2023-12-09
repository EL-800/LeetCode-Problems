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
    void Inorder(vector<int>& transversal, TreeNode* curr) {
        if (!curr)
            return;
        Inorder(transversal, curr->left);
        transversal.push_back(curr->val);
        Inorder(transversal, curr->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        Inorder(ans, root);
        return ans;
    }
};

int main(){
    return 0;
}