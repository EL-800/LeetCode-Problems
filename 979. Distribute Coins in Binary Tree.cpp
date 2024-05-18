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
    int moves = 0;

    int Distribuite(TreeNode* curr){
        if (!curr)
            return 0;
        int left = Distribuite(curr->left), right = Distribuite(curr->right);
        moves += abs(left) + abs(right);
        return curr->val + left + right - 1;        
    }

public:
    int distributeCoins(TreeNode* root) {
        Distribuite(root);
        return moves;
    }
};

int main(){
    return 0;
}