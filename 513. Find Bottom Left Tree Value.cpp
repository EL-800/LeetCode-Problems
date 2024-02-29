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
    void Find(int& maxLevel, int& currVal, TreeNode* curr, int currlevel = 0){
        if (!curr)
            return;
        Find(maxLevel, currVal, curr, currlevel + 1);
        Find(maxLevel, currVal, curr->right, currlevel + 1);
        if (currlevel > maxLevel){
            currVal = curr->val;
            maxLevel = currlevel;
        }            
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = -1, currVal = 0; 
        Find(maxLevel, currVal, root);
        return currVal;
    }
};

int main(){
    return 0;
}