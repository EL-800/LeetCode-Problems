#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pendingMoves;
        set<long long> visited;
        pendingMoves.push(1);
        while(visited.size() < n) {
            long long curr = pendingMoves.top();
            pendingMoves.pop();
            if (visited.count(curr))
                continue;
            visited.insert(curr);
            pendingMoves.push(curr * 2);
            pendingMoves.push(curr * 3);
            pendingMoves.push(curr * 5);
        }
        return *visited.rbegin();
    }
};

int main() {
    return 0;
}