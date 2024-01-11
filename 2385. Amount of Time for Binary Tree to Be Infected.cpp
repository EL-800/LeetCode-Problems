#include <bits/stdc++.h>
#include <unordered_set>

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
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;

    void toGraph(TreeNode* curr){
        if (!curr)
            return;
        if (curr->left) {
            graph[curr->val].push_back(curr->left->val);
            graph[curr->left->val].push_back(curr->val);
        }
        if (curr->right) {
            graph[curr->val].push_back(curr->right->val);
            graph[curr->right->val].push_back(curr->val);
        }
        toGraph(curr->left);
        toGraph(curr->right);
    }

    int dfs(int currNode){
        if (visited.count(currNode))
            return 0;
        visited.insert(currNode);
        int maxWay = 1;
        for (auto adjNode : graph[currNode])
            maxWay = max(maxWay, dfs(adjNode) + 1);        
        return maxWay;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        toGraph(root);
        return dfs(start) - 1;
    }
};

int main(){
    return 0;
}