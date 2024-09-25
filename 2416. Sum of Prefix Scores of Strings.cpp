#include <bits/stdc++.h>

using namespace std;

struct TrieNode{
    int value;
    unordered_map<char, TrieNode*> children;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        TrieNode *root = new TrieNode(), *curr = root;        
        for (auto word : words) {
            curr = root;
            for (auto letter : word) {
                if (!curr->children.count(letter))
                    curr->children[letter] = new TrieNode();
                curr = curr->children[letter];
                curr->value++;
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            curr = root;
            for (auto letter : words[i]) {
                curr = curr->children[letter];
                ans[i] += curr->value;
            }
        }
        return ans;
    }    
};

int main() {
    return 0;
}