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
    bool FindPath(TreeNode* curr, string& path, int obj) {
        if (!curr)
            return false;
        if (curr->val == obj)
            return true;
        if (FindPath(curr->left, path, obj)) {        
            path += "L";
            return true;
        }
        if (FindPath(curr->right, path, obj)) {
            path += "R";
            return true;
        }
        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "", destPath = "";
        FindPath(root, startPath, startValue);
        FindPath(root, destPath, destValue);
        reverse(startPath.begin(), startPath.end());
        reverse(destPath.begin(), destPath.end());
        int lcaInd = 0;
        while (lcaInd < min(startPath.length(), destPath.length()) && startPath[lcaInd] == destPath[lcaInd])
            lcaInd++;
        string ans = "";        
        for (int i = 0; i < startPath.length() - lcaInd; i++) 
            ans += "U";        
        ans += destPath.substr(lcaInd);
        return ans;
    }
};

int main() {
    return 0;
}