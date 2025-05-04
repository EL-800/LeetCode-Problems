#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<vector<int>, int> dominoesCount;
            for (auto domino : dominoes) {
                if (domino[0] > domino[1])
                    swap(domino[0], domino[1]);
                dominoesCount[domino]++;
            }
            int ans = 0;
            for (auto &[domino, val] : dominoesCount)
                ans += val * (val - 1) / 2;
            return ans;
        }
    };

int main() {
    return 0;
}