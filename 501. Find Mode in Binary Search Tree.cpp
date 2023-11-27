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
    int currVal = INT_MAX, currFreq = 0, maxFreq = 0;
    vector<int> modes;

    void Inorden(TreeNode* curr){
        if (!curr)
            return;
        Inorden(curr->left);
        if (curr->val == currVal)
            currFreq++;        
        else{
            currVal = curr->val;
            currFreq = 0;
        }
        if (currFreq == maxFreq)
            modes.push_back(currVal);                    
        if (currFreq > maxFreq){
            maxFreq = currFreq;
            modes.assign({currVal});
        }
        Inorden(curr->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        Inorden(root);
        return modes;
    }
};

int main(){
    return 0;
}