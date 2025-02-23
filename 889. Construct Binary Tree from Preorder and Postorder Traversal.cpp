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
        int preInd = 0;

        TreeNode* Rebuild(vector<int>& preorder, vector<int>& postorder, int posLeft, int posRight) {
            if (preInd >= preorder.size() || posLeft > posRight)
                return NULL;
            TreeNode* curr = new TreeNode(preorder[preInd++]);
            if (posLeft == posRight)
                return curr;
            int pivot = find(postorder.begin() + posLeft, postorder.begin() + posRight, preorder[preInd]) - postorder.begin();
            if (pivot <= posRight) {
                curr->left = Rebuild(preorder, postorder, posLeft, pivot);
                curr->right = Rebuild(preorder, postorder, pivot + 1, posRight - 1);
            }
            return curr;
        }

    public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            return Rebuild(preorder, postorder, 0, postorder.size() - 1);
        }
    };

int main() {
    return 0;
}