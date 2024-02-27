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
    int longestDiff = 0;

    int CalculateDiameter(TreeNode* curr){
        if (!curr)
            return 0;
        int left = CalculateDiameter(curr->left), right = CalculateDiameter(curr->right);
        longestDiff = max(longestDiff, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        CalculateDiameter(root);
        return longestDiff;
    }
};

int main(){
    return 0;
}