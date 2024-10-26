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
public:    
    int depth[100002], levels[100002], max1[100002], max2[100002];

    int CalcualteDepht(TreeNode* curr, int currlevel) {
        if (!curr) 
            return 0;
        levels[curr->val] = currlevel;
        depth[curr->val] = 1 + max(CalcualteDepht(curr->left, currlevel + 1), CalcualteDepht(curr->right, currlevel + 1));    
        if (max1[currlevel] < depth[curr->val]) {
            max2[currlevel] = max1[currlevel];
            max1[currlevel] = depth[curr->val];
        } 
        else if (max2[currlevel] < depth[curr->val])
            max2[currlevel] = depth[curr->val];        
        return depth[curr->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        CalcualteDepht(root, 0);
        vector<int> ans;
        for (int query : queries) {            
            int level = levels[query];
            ans.push_back((max1[level] == depth[query] ? max2[level] : max1[level]) + level - 1);
        }
        return ans;
    }
};

int main() {
    return 0;

}