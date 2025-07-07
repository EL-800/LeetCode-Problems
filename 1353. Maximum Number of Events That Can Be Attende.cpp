#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = 1e5, ans = 0, eventInd = 0;
        priority_queue<int, vector<int>, greater<>> currRanks;
        sort(events.begin(), events.end());
        for (int i = 1; i <= n; i++) {            
            while (eventInd < events.size() && events[eventInd][0] <= i) {
                currRanks.push(events[eventInd][1]);
                eventInd++;
            } 
            while (!currRanks.empty() && currRanks.top() < i)
                currRanks.pop();
            if (!currRanks.empty()) {           
                currRanks.pop();
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}