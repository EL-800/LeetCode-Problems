#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(),  m = worker.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++)
            jobs.push_back({profit[i], difficulty[i]});
        sort(jobs.rbegin(), jobs.rend());
        sort(worker.rbegin(), worker.rend());
        int ans = 0, jobInd = 0, workerInd = 0;
        while (workerInd < m && jobInd < n){
            auto [profit, diff] = jobs[jobInd];
            if (worker[workerInd] >= diff) {
                workerInd++;
                ans += profit;
            }
            else
                jobInd++;
        }
        return ans;        
    }
};

int main(){
    return 0;
}