#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size(), n2 = n * n, repeated;
            vector<bool> unseen(n2 + 1, 1);
            for (auto row : grid) {
                for (int num : row) {
                    if (!unseen[num])
                        repeated = num;
                    else
                        unseen[num] = 0;
                }
            }
            int missing = find(unseen.begin() + 1, unseen.end(), true) - unseen.begin();
            return {repeated, missing};
        }
    };

int main() {
    return 0;
}