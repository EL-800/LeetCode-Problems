#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        int n = startTime.size(), left = 0, right = 0, empties = 0;                       
        for (; right < k + 1 && right < n; right++)
            empties += startTime[right] - ((right - 1 >= 0) ? endTime[right - 1] : 0);                            
        int ans = empties;
        for (; right < n; right++, left++) {
            empties += startTime[right] - ((right - 1 >= 0) ? endTime[right - 1] : 0);
            empties -= startTime[left] - ((left - 1 >= 0) ? endTime[left - 1] : 0);           
            ans = max(ans, empties);            
        }
        return ans;
    }
};

int main() {
    return 0;
}