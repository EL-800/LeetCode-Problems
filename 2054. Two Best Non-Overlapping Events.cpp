#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<int> maxSuffixVal(n + 1);
        sort(events.begin(), events.end());
        
        for (int i = n - 1; i >= 0; i--) 
            maxSuffixVal[i] = max(maxSuffixVal[i + 1], events[i][2]);        
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int notOverlappingInd = lower_bound(events.begin() + i, events.end(), vector<int>({events[i][1] + 1, 0, 0})) - events.begin();
            ans = max(ans, events[i][2] + maxSuffixVal[notOverlappingInd]);
        }
        
        return ans;
    }
};

int main() {
    return 0;
}