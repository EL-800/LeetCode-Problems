#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int DP(vector<vector<int>>& books, vector<int>& memo, int shelfWidth, int i = 0) { 
        if (i == books.size())
            return 0;       
        if (memo[i] != INT_MAX)
            return memo[i];
        int maxHeight = 0, currWidth = 0;
        for (int j = i, currWidth = 0; j < books.size(); j++) {            
            currWidth += books[j][0];
            if (currWidth > shelfWidth)
                break;
            maxHeight = max(maxHeight, books[j][1]);            
            memo[i] = min(memo[i], DP(books, memo, shelfWidth, j + 1) + maxHeight);
        }
        return memo[i];
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> memo(books.size(), INT_MAX);
        return DP(books, memo, shelfWidth);
    }
};

int main() {
    vector<vector<int>> c = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    Solution s;
    cout << s.minHeightShelves(c, 4);
    return 0;
}