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
    vector<long long> levelSum;

    void Travel(TreeNode *curr, int currLvl = 0) {
        if (!curr)
            return;
        if (levelSum.size() <= currLvl)            
            levelSum.push_back(0);
        levelSum[currLvl] += (long long)curr->val;
        Travel(curr->left, currLvl + 1);
        Travel(curr->right, currLvl + 1);
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        Travel(root);
        sort(levelSum.rbegin(), levelSum.rend());
        return levelSum.size() >= k ? levelSum[k - 1] : -1;
    }
};

int main() {
    return 0;
}