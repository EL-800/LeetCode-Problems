#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){
            if (a[1] == b[1])
                return a[0] > b[0];
            return a[1] < b[1];
        });

        int lastInd1 = -1, lastInd2 = -1, ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];

            bool found1 = (lastInd1 >= left && lastInd1 <= right);
            bool found2 = (lastInd2 >= left && lastInd2 <= right);

            if (found1 && found2) 
                continue;          
            else if (found2) {                                              
                ans++;
                lastInd1 = lastInd2;
                lastInd2 = right;
            }
            else if (found1) {                  
                ans++;
                lastInd2 = right;
                lastInd1 = right - 1;
            }
            else {               
                ans += 2;
                lastInd1 = right - 1;
                lastInd2 = right;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}