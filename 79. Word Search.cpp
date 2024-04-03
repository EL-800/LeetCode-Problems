#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m, s;    
    string word;
    vector<vector<char>> board;
    vector<vector<bool>> vis;
    vector<pair<int, int>> moves = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    bool Search(int curry, int currx, int curri = 0) {
        if (curry < 0 || curry >= n)
            return false;
        if (currx < 0 || currx >= m)
            return false;
        if (word[curri] != board[curry][currx])
            return false;
        if (vis[curry][currx])
            return false;
        if (curri == s)
            return true; 
        vis[curry][currx] = true;
        for (auto i : moves) {
            if (Search(curry + i.first, currx + i.second, curri + 1))
                return true;
        }
        vis[curry][currx] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        s = word.size() - 1;
        n = board.size();
        m = board[0].size();
        vis.assign(n, vector<bool>(m));
        this->board = board;
        this->word = word;      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (Search(i, j))
                    return true;
            }
        }
        return false;
    }
};

int main(){
    return 0;
}