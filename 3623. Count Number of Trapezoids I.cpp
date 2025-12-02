#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9 + 7;
        unordered_map<int, long long> groupSize;
        for (auto point : points) {
            int y = point[1];
            groupSize[y]++;
        }

        long long totalSum = 0;
        for (auto &group : groupSize) {            
            group.second = group.second * (group.second - 1) / 2;                    
            totalSum += group.second;
        }
        
        long long ans = 0;
        for (auto group : groupSize) {
            totalSum -= group.second;
            ans = (ans + group.second * totalSum) % mod;
        }

        return int(ans % mod);
    }
};

int main() {
    vector<vector<int>> c = {{1,0},{2,0},{3,0},{2,2},{3,2}};
    Solution s;
    cout << s.countTrapezoids(c);
    return 0;
}