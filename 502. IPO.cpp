#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> project;
        priority_queue<int> bestCurrProfit;
        int n = profits.size();
        for (int i = 0; i < n; i++)
            project.push_back({ capital[i], profits[i] });
        sort(project.begin(), project.end());
        int taken = 0, curr = 0;
        while (taken < k) {
            while (curr < n && project[curr].first <= w)
                bestCurrProfit.push(project[curr++].second);
            if (bestCurrProfit.empty())
                break;
            w += bestCurrProfit.top();
            bestCurrProfit.pop();
            taken++;
        }
        return w;
    }
};

int main(){
    return 0;
}