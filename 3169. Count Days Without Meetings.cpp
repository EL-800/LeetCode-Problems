#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            map<int, int> sweepLine;
            for (auto meeting : meetings) {
                sweepLine[meeting[0]]++;
                sweepLine[meeting[1] + 1]--;
            }            
            int ans = 0, last = 1, opens = 0;
            for (auto [ind, val] : sweepLine) {
                if (!opens)
                    ans += ind - last;
                opens += val;
                last = ind;
            }
            return ans + max(days - last + 1, 0);
        }
    };

int main() {
    return 0;
}