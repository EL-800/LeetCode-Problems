#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:    
    void PostOrder(vector<int> &ans, Node *curr) {
        if(!curr)
            return;
        for(auto child : curr->children) 
            PostOrder(ans, child);
        ans.push_back(curr->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        PostOrder(ans, root);
        return ans;
    }
};

int main() {
    return 0;
}