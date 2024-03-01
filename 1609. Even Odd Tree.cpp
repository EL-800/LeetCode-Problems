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
    void TreeToList(unordered_map<int, vector<int>>& list, TreeNode* currNode, int lvl = 0){
        if (!currNode)
            return;
        list[lvl].push_back(currNode->val);
        TreeToList(list, currNode->left, lvl + 1);
        TreeToList(list, currNode->right, lvl + 1);
    }

public:
    bool isEvenOddTree(TreeNode* root) {
        unordered_map<int, vector<int>> list;
        TreeToList(list, root);
        for (auto ind : list){
            int lvl = ind.first;
            vector<int>& lvlValues = ind.second;            
            for (int j = 0; j < lvlValues.size(); j++){
                if (!(lvl % 2)){
                    if (!(lvlValues[j] % 2))
                        return false;
                    if (j != lvlValues.size() - 1 && lvlValues[j] >= lvlValues[j + 1])
                        return false;
                }
                else {
                    if (lvlValues[j] % 2)
                        return false;
                    if (j != lvlValues.size() - 1 && lvlValues[j] <= lvlValues[j + 1])
                        return false;
                }
            }
        }
        return true;
    }
};

int main(){
    return 0;
}