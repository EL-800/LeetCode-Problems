#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> available;
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<>> unavailable;

        for (int i = 0; i < n; i++) 
            available.push({servers[i], i});

        long long t = 0;
        vector<int> ans;        
        
        for (int i = 0; i < m; i++) {
            int task = tasks[i];
            t = max(t, i * 1ll);
            while (!unavailable.empty() && unavailable.top()[0] <= t) {
                available.push({unavailable.top()[1], unavailable.top()[2]});
                unavailable.pop();
            }   

            if (available.empty()) {
                t = unavailable.top()[0];
                while (!unavailable.empty() && unavailable.top()[0] <= t) {
                    available.push({unavailable.top()[1], unavailable.top()[2]});
                    unavailable.pop();
                }                               
            }            

            ans.push_back(available.top().second);
            unavailable.push({t + task * 1ll, available.top().first * 1ll, available.top().second * 1ll});
            available.pop();
        }

        return ans;
    }
};

int main() {
    return 0;
}