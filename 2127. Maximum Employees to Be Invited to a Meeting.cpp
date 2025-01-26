#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorites) {
        int n = favorites.size();        
        vector<int> inDegree(n), chains(n);
        vector<bool> visited(n);
        queue<int> pendingMoves;
        for (int favorite : favorites) {
            inDegree[favorite]++;
        }        
        for (int i = 0; i < n; i++) {
            if (!inDegree[i]) 
                pendingMoves.push(i);            
        }
        while (!pendingMoves.empty()) {
            int curr = pendingMoves.front();
            pendingMoves.pop();
            visited[curr] = true;
            int adj = favorites[curr];
            chains[adj] = chains[curr] + 1;
            if (!(--inDegree[adj])) 
                pendingMoves.push(adj);            
        }
        int maxCycle = 0, totalChains = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            int current = i, size = 0;
            while (!visited[current]) {
                visited[current] = true;
                current = favorites[current];
                size++;
            }
            if (size == 2) 
                totalChains += 2 + chains[i] + chains[favorites[i]];
            else 
                maxCycle = max(maxCycle, size);                                            
        }
        return max(maxCycle, totalChains);
    }
};

int main() {
    return 0;
}