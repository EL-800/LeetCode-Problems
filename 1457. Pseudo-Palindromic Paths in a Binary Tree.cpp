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
    int FindPaths(TreeNode* curr, vector<int>& numbers) {
        numbers[curr->val]++;
        if (!curr->left && !curr->right) {
            int size = 0, error = 0;            
            for (int i : numbers) {
                size += i;
                if (i % 2)
                    error++;                                                                       
            }
            numbers[curr->val]--;
            if ((!(size % 2) && !error) || (size % 2 && error == 1))
                return 1;  
            return 0;
        }
        int left = 0, right = 0;
        if (curr->left)
            left = FindPaths(curr->left, numbers);
        if (curr->right)
            right = FindPaths(curr->right, numbers);
        numbers[curr->val]--;
        return left + right;
    }
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> numbers = vector<int>(10);
        return FindPaths(root, numbers);
    }
};

int main(){
    return 0;
}