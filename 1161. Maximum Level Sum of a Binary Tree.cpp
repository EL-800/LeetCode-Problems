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
    int maxLevelSum(TreeNode* root) {
        int currLevel = 1, currSum = 0, bestSum = INT_MIN, bestLevel = 1;
        queue<pair<TreeNode*, int>> pendingMoves;
        pendingMoves.push({root, 1});
        while (!pendingMoves.empty()) {
            auto [node, level] = pendingMoves.front();
            pendingMoves.pop();                      

            if (currLevel != level) {
                if (currSum > bestSum) {
                    bestSum = currSum;
                    bestLevel = currLevel;
                }
                currSum = 0;
                currLevel = level;
            }

             if (!node)
                continue; 

            currSum += node->val;         
            pendingMoves.push({node->left, level + 1});
            pendingMoves.push({node->right, level + 1});
        }

        return bestLevel;
    }
};

int main() {
    return 0;
}