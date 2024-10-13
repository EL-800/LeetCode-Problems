#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> sweepLine;
        for (auto interval : intervals) {
            sweepLine[interval[0]]++;
            sweepLine[interval[1] + 1]--;
        }
        int currOpens = 0, maxOpens = 0;
        for (auto [k, v] : sweepLine) {
            currOpens += v;
            maxOpens = max(maxOpens, currOpens);
        }
        return maxOpens;
    }
};

int main() {
    return 0;
}