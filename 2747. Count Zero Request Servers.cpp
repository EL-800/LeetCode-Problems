#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<vector<int>> indexedQueries;
        for (int i = 0; i < queries.size(); i++) 
            indexedQueries.push_back({queries[i], i});

        sort(logs.begin(), logs.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        sort(indexedQueries.begin(), indexedQueries.end());

        unordered_map<int, int> usedServers;
        vector<int> ans(queries.size());
        int left = 0, right = 0;
        for (int i = 0; i < indexedQueries.size(); i++) {
            int rangeS = indexedQueries[i][0] - x, rangeE = indexedQueries[i][0], realInd = indexedQueries[i][1];
            while(right < logs.size() && logs[right][1] <= rangeE) {
                usedServers[logs[right][0]]++;            
                right++;
            }
            
            while (left < right && logs[left][1] < rangeS) {
                usedServers[logs[left][0]]--;
                if (!usedServers[logs[left][0]])            
                    usedServers.erase(logs[left][0]);
                left++;
            }

            ans[realInd] = n - usedServers.size();
        }

        return ans;
    }
};

int main() {
    return 0;
}