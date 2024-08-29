#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int removedStones = 0;
    vector<int> parents;

    int Find(int curr) {
        if (parents[curr] == curr)
            return curr;
        return Find(parents[curr]);
    }

    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) {
            removedStones++;
            parents[u] = v;
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parents.assign(n, 0);
        for (int i = 0; i < n; i++)
            parents[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    Union(i, j);
            }
        }
        return removedStones;
    }
};

int main() {
    return 0;
}