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
        int deepest = 0;
        TreeNode* ans;

        int PostOrder(TreeNode* curr, int depht = 0) {
            if (!curr)
                return depht;
            int leftDepht = PostOrder(curr->left, depht + 1), rightDepht = PostOrder(curr->right, depht + 1);
            deepest = max({leftDepht, rightDepht, deepest});
            if (deepest == leftDepht && deepest == rightDepht)
                ans = curr;
            return max(leftDepht, rightDepht);
        } 

    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            PostOrder(root);
            return ans;
        }
    };

int main() {
    return 0;
}