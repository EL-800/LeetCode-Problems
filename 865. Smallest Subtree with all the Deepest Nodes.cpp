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
    int deepestLevel = 0;
    vector<pair<TreeNode*, int>> deepestSubs;

    void GetDeepest(TreeNode* curr, int currLevel = 0) {
        if (!curr)
            return;

        deepestLevel = max(deepestLevel, currLevel);          

        GetDeepest(curr->left, currLevel + 1);
        GetDeepest(curr->right, currLevel + 1);
    }

    bool GetSmallestSub(TreeNode* curr, int currLevel = 0) {
        if (!curr)
            return false;        
            
        bool hasDeepests = GetSmallestSub(curr->left, currLevel + 1) | GetSmallestSub(curr->right, currLevel + 1) | deepestLevel == currLevel;
        if (hasDeepests)
            deepestSubs[currLevel].first = curr;         
        deepestSubs[currLevel].second += hasDeepests;
        return hasDeepests;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        GetDeepest(root);
        deepestSubs.resize(deepestLevel + 1);
        GetSmallestSub(root);

        int ans = deepestLevel;
        while (deepestSubs[deepestLevel].second != 1)
            deepestLevel--;
        
        return deepestSubs[deepestLevel].first;
    }
};

int main() {
    return 0;
}