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
    TreeNode* GetNode(unordered_map<int, pair<TreeNode*, bool>>& assigneds, int val) {
        if (!assigneds[val].first)
            assigneds[val].first = new TreeNode(val);
        return assigneds[val].first;
    }    

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<TreeNode*, bool>> assigneds;
        for (auto description: descriptions) {
            if (description[2]) {
                TreeNode *parent = GetNode(assigneds, description[0]), *child = GetNode(assigneds, description[1]);                
                parent->left = child;
                assigneds[description[1]].second = true;
            }
            else {
                TreeNode *parent = GetNode(assigneds, description[0]), *child = GetNode(assigneds, description[1]);                
                parent->right = child;
                assigneds[description[1]].second = true;
            }
        }
        for (auto i : assigneds) {
            if (!i.second.second)
                return i.second.first;
        }
        return new TreeNode();
    }
};

int main() {
    return 0;
}