#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> BFS(vector<int>& edges, int beg) {
        queue<pair<int, int>> pendingMoves;
        vector<int> visited(edges.size(), -1);
        pendingMoves.push({ beg, 0 });
        while (!pendingMoves.empty()) {
            pair<int, int> curr = pendingMoves.front();
            pendingMoves.pop();
            if (curr.first == -1)
                continue;
            if (visited[curr.first] != -1)
                continue;
            visited[curr.first] = curr.second;
            pendingMoves.push({ edges[curr.first], curr.second + 1 });
        }
        return visited;
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {        
        vector<int> shortests1 = BFS(edges, node1);
        vector<int> shortests2 = BFS(edges, node2);
        int shortest = INT_MAX, index = -1;
        for (int i = 0; i < edges.size(); i++) {
            if (shortests1[i] != -1 && shortests2[i] != -1)
                if (max(shortests1[i], shortests2[i]) < shortest) {
                    shortest = max(shortests1[i], shortests2[i]);
                    index = i;
                }
        }
        return index;
    }
};

int main() {
    return 0;
}