#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool CheckPath(ListNode* currLN, TreeNode* currTN) {
        if (!currLN)
            return true;
        if (!currTN)
            return false;
        if (currTN->val != currLN->val)
            return false;
        return CheckPath(currLN->next, currTN->left) || CheckPath(currLN->next, currTN->right);
    }    

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root)
            return false;
        if (CheckPath(head, root))
            return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

int main() {
    return 0;
}