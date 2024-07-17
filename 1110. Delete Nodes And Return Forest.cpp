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
    void DeleteNodes(vector<bool>& deleteBucket, vector<TreeNode*>& ans, TreeNode *&curr, bool isRoot = true) {
        if (!curr)
            return;
        DeleteNodes(deleteBucket, ans, curr->left, deleteBucket[curr->val]);
        DeleteNodes(deleteBucket, ans, curr->right, deleteBucket[curr->val]);
        if (!deleteBucket[curr->val] && isRoot) ans.push_back(curr);        
        else if (deleteBucket[curr->val]) curr = nullptr;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<bool> deleteBucket(*max_element(to_delete.begin(), to_delete.end()) + 1);        
        for (int d : to_delete)
            deleteBucket[d] = true;
        vector<TreeNode*> ans;
        DeleteNodes(deleteBucket, ans, root);
        return ans;
    }
};

int main() {
    return 0;
}