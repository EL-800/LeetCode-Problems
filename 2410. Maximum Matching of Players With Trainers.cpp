#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int n = players.size(), m = trainers.size(), plaInd = 0, traInd = 0;        
        while (plaInd < n && traInd < m) {
            if (players[plaInd] <= trainers[traInd])
                plaInd++;
            traInd++;
        }
        return plaInd;
    }
};

int main() {
    return 0;
}