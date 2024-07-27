#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> GetDistancesOfNode(vector<vector<pair<int, int>>>& graph, int node) {
        vector<int> distances(graph.size(), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pendingMoves;
        pendingMoves.push({0, node});
        while (!pendingMoves.empty()) {
            auto [dist, node] = pendingMoves.top();
            pendingMoves.pop();
            if (distances[node] != -1)
                continue;
            distances[node] = dist;
            for (auto [adjNode, adjDist] : graph[node]) 
                pendingMoves.push({adjDist + dist, adjNode});
        }
        return distances;
    }

    vector<vector<int>> GetDistances(vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> graph(26);
        for (int i = 0; i < original.size(); i++)
            graph[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        vector<vector<int>> distances;
        for (int i = 0; i < graph.size(); i++) 
            distances.push_back(GetDistancesOfNode(graph, i));   
        return distances;     
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> distances = GetDistances(original, changed, cost);
        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            long long dist = (long long)distances[source[i] - 'a'][target[i] - 'a'];
            if (dist == -1)
                return -1;
            ans += dist;
        }
        return ans;
    }
};

int main() {
    return 0;
}