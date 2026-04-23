#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    struct Trie {
        Trie* linkeds[26];
        bool last = false;

        Trie() {
            memset(linkeds, NULL, 26 * sizeof(Trie*));
        }
    };

    Trie *root = new Trie();

    void Insert(string &word) {
        Trie* curr = root;
        for (char c : word) {
            int iC = c - 'a';
            if (!curr->linkeds[iC])
                curr->linkeds[iC] = new Trie();
            curr = curr->linkeds[iC];
        }
        curr->last = true;
    }

    bool Search(string &word, Trie *curr, int ind = 0, int edits = 0) {
        if (edits > 2)
            return false;
        if (ind == word.length())
            return curr->last;

        for (int i = 0; i < 26; i++) {
            if (!curr->linkeds[i])
                continue;
            int auxEdits = edits + (i != word[ind] - 'a');
            if (Search(word, curr->linkeds[i], ind + 1, auxEdits))
                return true;            
        }

        return false;
    }

public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        for (auto &word : dictionary)
            Insert(word);
        
        vector<string> ans;
        for (auto &word : queries) {
            if (Search(word, root))
                ans.push_back(word);
        }

        return ans;
    }
};

int main() {
    return 0;
}