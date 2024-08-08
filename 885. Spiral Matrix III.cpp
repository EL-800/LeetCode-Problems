#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        int currSize = 0, currMove = 0;
        while (true) {
            if (currMove == 0 || currMove == 2)
                currSize++;
            for (int i = 0; i < currSize; i++) {
                rStart += moves[currMove].first;
                cStart += moves[currMove].second;
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    ans.push_back({rStart, cStart});  
                if (ans.size() == rows * cols)
                    return ans;                              
            }
            currMove = (currMove + 1) % 4;
        }
        return ans;
    }
};

int main() {
    return 0;
}