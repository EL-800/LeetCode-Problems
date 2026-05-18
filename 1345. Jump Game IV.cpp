#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = (int)arr.size();
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)
            graph[arr[i]].push_back(i);
        queue<pair<int, int>> pendingMoves;
        pendingMoves.push({ 0,0 });
        vector<bool> visited(n);
        while (!pendingMoves.empty()) {
            auto curr = pendingMoves.front();
            pendingMoves.pop();
            if (curr.first < 0 || curr.first >= n)
                continue;
            if (visited[curr.first])
                continue;
            visited[curr.first] = true;
            if (curr.first == n - 1)
                return curr.second;
            pendingMoves.push({ curr.first + 1, curr.second + 1 });
            pendingMoves.push({ curr.first - 1, curr.second + 1 });
            for (int adj : graph[arr[curr.first]]) {
                if (adj != curr.first)
                    pendingMoves.push({ adj, curr.second + 1 });
            }
            graph[arr[curr.first]].clear();
        }
        return -1;
    }
};

int main() {
    return 0;
}