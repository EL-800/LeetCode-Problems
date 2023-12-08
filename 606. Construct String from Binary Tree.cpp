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
    string tree2str(TreeNode* curr) {
        if (!curr)
            return "";
        string val = to_string(curr->val);
        string left = "(" + tree2str(curr->left) + ")";
        string right = "(" + tree2str(curr->right) + ")";
        if (right != "()")
            return val + left + right;
        else if (left != "()")
            return val + left;
        return val;
    }
};

int main(){
    return 0;
}