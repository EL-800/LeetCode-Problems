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
    vector<vector<int>> levels;

    void GetLevelValues(TreeNode *curr, int currLevel = 0) {
        if (!curr)
            return;
        if (currLevel == levels.size())
            levels.push_back(vector<int>());
        levels[currLevel].push_back(curr->val);
        GetLevelValues(curr->left, currLevel + 1);
        GetLevelValues(curr->right, currLevel + 1);
    }

public:
    int minimumOperations(TreeNode* root) {        
        GetLevelValues(root);
        int ans = 0;
        for (auto level : levels) {
            vector<int> sortedLevel(level.begin(), level.end());            
            unordered_map<int, int> indexes;
            for (int i = 0; i < level.size(); i++) 
                indexes[level[i]] = i;
            sort(sortedLevel.begin(), sortedLevel.end());
            for (int i = 0; i < sortedLevel.size(); i++) {
                if (indexes[sortedLevel[i]] != i) {                    
                    indexes[level[i]] = indexes[sortedLevel[i]]; 
                    swap(level[i], level[indexes[sortedLevel[i]]]);                   
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}