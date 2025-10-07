#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> floodedLakes;
        set<int> dryDays; 
        vector<int> ans(n, -1);   
        
        for (int i = 0; i < n; i++) {
            if (!rains[i]) {
                ans[i] = 1;
                dryDays.insert(i);
                continue;
            }
            if (floodedLakes.count(rains[i])) {                
                auto it = dryDays.upper_bound(floodedLakes[rains[i]]);
                if (it == dryDays.end())
                    return {};
                ans[*it] = rains[i];
                dryDays.erase(it);
            }                            
            floodedLakes[rains[i]] = i;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> c = {2,3,0,0,3,1,0,1,0,2,2};
    s.avoidFlood(c);
    return 0;
}