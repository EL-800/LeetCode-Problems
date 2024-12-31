#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<int> dp;

    int FindMin(vector<int>& days, vector<int>& cost, int d = 0) {
        if (d >= n)
            return 0;
        if (dp[d])
            return dp[d];
        int ticket1 = FindMin(days, cost, int(lower_bound(days.begin(), days.end(), days[d] + 1) - days.begin())) + cost[0];
        int ticket2 = FindMin(days, cost, int(lower_bound(days.begin(), days.end(), days[d] + 7) - days.begin())) + cost[1];
        int ticket3 = FindMin(days, cost, int(lower_bound(days.begin(), days.end(), days[d] + 30) - days.begin())) + cost[2];
        return dp[d] = min({ ticket1, ticket2, ticket3 });
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = (int)days.size();
        dp.assign(n, 0);
        return FindMin(days, costs);
    }
};

int main() {
    return 0;
}