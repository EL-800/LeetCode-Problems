#include <bits/stdc++.h>
#include <array>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pendingMoves;
        vector<vector<pair<int, int>>> graph(n);
        vector<pair<int, int>> best(n, {INT_MAX, INT_MAX});
        for (vector<int> flight : flights)
            graph[flight[0]].push_back({ flight[1], flight[2] });        
        pendingMoves.push({ 0, 0, src });
        while (!pendingMoves.empty()) {
            auto curr = pendingMoves.top();
            pendingMoves.pop();      
            if (curr[1] > k && curr[2] != dst)
                continue;
            if (curr[2] == dst)
                return curr[0];
            if (curr[1] > best[curr[2]].second)
                continue;
            best[curr[2]] = { curr[0], curr[1] };
            for (pair<int, int> i : graph[curr[2]])
                pendingMoves.push({ i.second + curr[0], curr[1] + 1, i.first });
        }
        return -1;
    }
};

int main(){
    return 0;
}