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
    void SetParents(unordered_map<TreeNode*, TreeNode*> &parents, TreeNode* curr) {
        if (!curr)
            return;
        if (curr->left)
            parents[curr->left] = curr;
        if (curr->right)
            parents[curr->right] = curr;
        SetParents(parents, curr->left);
        SetParents(parents, curr->right);
    }

    int DFS(unordered_map<TreeNode*, TreeNode*> &parents, unordered_set<TreeNode*> &visited, int maxDistance, TreeNode* curr, int currDistance = 0, bool isFirst = true) {
        if (!curr)
            return 0;        
        if (currDistance > maxDistance)
            return 0;
        if (visited.count(curr))
            return 0;
        visited.insert(curr);
        if (!isFirst && !curr->left && !curr->right)
            return 1;
        return DFS(parents, visited, maxDistance, curr->left, currDistance + 1, false) + DFS(parents, visited, maxDistance, curr->right, currDistance + 1, false) 
        + DFS(parents, visited, maxDistance, parents[curr], currDistance + 1, false);
    }

    int SearchLeafs(unordered_map<TreeNode*, TreeNode*> &parents, int maxDistance, TreeNode* curr) {
        if (!curr)
            return 0;
        if (!curr->left && !curr->right) {
            unordered_set<TreeNode*> visited;
            return DFS(parents, visited, maxDistance, curr);
        }
        return SearchLeafs(parents, maxDistance, curr->left) + SearchLeafs(parents, maxDistance, curr->right);
    }

public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = nullptr;
        SetParents(parents, root);
        return SearchLeafs(parents, distance, root) / 2;
    }
};

int main() {
    return 0;
}