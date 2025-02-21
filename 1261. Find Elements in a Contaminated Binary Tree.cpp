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
 

class FindElements {
    private:
        unordered_set<int> presents;

        void SetTree(TreeNode* curr) {
            presents.insert(curr->val);
            if (curr->left) {                
                curr->left->val = 2 * curr->val + 1;
                SetTree(curr->left);
            }
            if (curr->right) {
                curr->right->val = 2 * curr->val + 2;
                SetTree(curr->right);
            }
        } 

    public:
        FindElements(TreeNode* root) {
            root->val = 0;
            SetTree(root);
        }
        
        bool find(int target) {
            return presents.count(target);
        }
    };

int main() {
    return 0;
}