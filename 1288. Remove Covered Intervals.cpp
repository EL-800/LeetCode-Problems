#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int lastEnd = 0, ans = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });        
        
        for (auto &interval : intervals) {
            if (lastEnd >= interval[1])
                ans--;
            lastEnd = max(lastEnd, interval[1]);
        }

        return ans;
    }
};

int main() {
    return 0;
}