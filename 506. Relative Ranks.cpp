#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int, int> mappedScores;
        vector<string> mappedRank(max(n, 3));        
        for (int i = 0; i < n; i++) {
            mappedScores[score[i]] = i;
            mappedRank[i] = to_string(i + 1);
        }
        mappedRank[0] = "Gold Medal";
        mappedRank[1] = "Silver Medal";
        mappedRank[2] = "Bronze Medal";
        sort(score.rbegin(), score.rend());
        vector<string> ranks(n);
        for (int i = 0; i < n; i++)
            ranks[mappedScores[score[i]]] = mappedRank[i];        
        return ranks;
    }
};

int main(){    
    return 0;
}