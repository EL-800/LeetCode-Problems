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
    void PostOrder(vector<int> &ans, TreeNode *curr) {
        if (!curr)
            return;
        PostOrder(ans, curr->left);
        PostOrder(ans, curr->right);
        ans.push_back(curr->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        PostOrder(ans, root);
        return ans;
    }
};

int main() {
    return 0;
}