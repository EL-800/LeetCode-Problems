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
    int averageCount = 0;

    pair<int, int> CountAvarage(TreeNode* curr){
        if (!curr)
            return {0, 0};
        pair<int, int> left = CountAvarage(curr->left), right = CountAvarage(curr->right);        
        int sum = left.first + right.first + curr->val, n = left.second + right.second + 1;
        if (sum / n == curr->val)
            averageCount++;
        return {sum, n};        
    }

public:
    int averageOfSubtree(TreeNode* root) {
        averageCount = 0;
        CountAvarage(root);
        return averageCount;
    }
};

int main(){
    return 0;
}