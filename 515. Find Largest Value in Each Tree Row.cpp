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
    void DFS(vector<int>& rowsMax, TreeNode* curr, int level = 0) {
        if (!curr)
            return;
        if (rowsMax.size() == level)
            rowsMax.push_back(INT_MIN);
        rowsMax[level] = max(rowsMax[level], curr->val);
        DFS(rowsMax, curr->left, level + 1);
        DFS(rowsMax, curr->right, level + 1);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        DFS(ans, root);
        return ans;
    }
};

int main(){
    return 0;
}