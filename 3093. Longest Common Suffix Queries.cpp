#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    int lowestSize = INT_MAX; 
    int lowestInd = INT_MAX;
    TrieNode* letters[26];    
};

static constexpr int N = 500003; 
static TrieNode pool[N];
static int ptr = 0;   

struct Trie {
    TrieNode* root;    

    Trie() { 
        ptr = 0;       
        root = newNode();
    }

    TrieNode* newNode() {
        TrieNode *node = &pool[ptr++];  
        memset(node->letters, 0, sizeof(node->letters));
        node->lowestSize = INT_MAX;
        node-> lowestInd = -1;              
        return node;
    }

    void Insert(string& word, int ind) {
        int n = word.size();
        TrieNode* curr = root;
        
        if (n < curr->lowestSize) {
            curr->lowestSize = n;
            curr->lowestInd = ind;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            int c = word[i] - 'a';
            if (curr->letters[c]==NULL) 
                curr->letters[c] = newNode();
            curr=curr->letters[c];

            if (n < curr->lowestSize) {
                curr->lowestSize=n;
                curr->lowestInd=ind;
            }
        }
    }

    int Find(const string& q) {
        TrieNode* curr = root;
        int best=root->lowestInd;
        
        for (int i = q.size() - 1; i >= 0; i--) {
            int c = q[i] - 'a';
            if (!curr->letters[c]) 
                break; 
            curr = curr->letters[c];
            best = curr->lowestInd;
        }
        return best;
    }
};

class Solution {
public:
    static vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        Trie trie;        

        for (int i = 0; i < n; i++) 
            trie.Insert(wordsContainer[i], i);

        vector<int> ans;        
        for (auto& word : wordsQuery) 
            ans.push_back(trie.Find(word));
        
        return ans;
    }
};

auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main() {
    return 0;
}