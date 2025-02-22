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
        int ind = 0, level = 0;

        void GetCurrLevel(string &traversal) {  
            level = 0;          
            while (ind < traversal.length() && traversal[ind] == '-') {
                level++;
                ind++;
            }            
        }

        int GetNumber(string &traversal) {
            int number = 0;
            while (traversal[ind] != '-') {
                number *= 10;
                number += traversal[ind] - '0';
                ind++;
            }         
            return number;       
        }

        void Rebuild(string &traversal, TreeNode *curr, int currLevel = 0) {
            if (ind >= traversal.size())
                return;
            GetCurrLevel(traversal);
            if (currLevel < level) {
                curr->left = new TreeNode(GetNumber(traversal));
                Rebuild(traversal, curr->left, currLevel + 1);
            }            
            if (ind >= traversal.size())
                return;
            if (currLevel < level) {
                curr->right = new TreeNode(GetNumber(traversal));
                Rebuild(traversal, curr->right, currLevel + 1);
            }
        }

    public:
        TreeNode* recoverFromPreorder(string traversal) {
            TreeNode* root = new TreeNode(GetNumber(traversal));
            Rebuild(traversal, root);
            return root;
        }
    };

int main() {
    return 0;
}