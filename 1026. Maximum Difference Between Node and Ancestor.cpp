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
    void FindMaxDiff(TreeNode* curr, int minV, int maxV, int &ans) {
        if (!curr)
            return;
        int newMin = min(minV, curr->val), newMax = max(maxV, curr->val);
        ans = max(ans, abs(newMin - newMax));
        FindMaxDiff(curr->left, newMin, newMax, ans);
        FindMaxDiff(curr->right, newMin, newMax, ans);
    }

public:
    int maxAncestorDiff(TreeNode* root) {        
        int ans = 0; 
        FindMaxDiff(root, root->val, root->val, ans);
        return ans;
    }
};

int main(){
    return 0;
}