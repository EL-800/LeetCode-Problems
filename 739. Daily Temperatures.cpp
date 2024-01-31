#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;        
        int n = temperatures.size();        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top().first < temperatures[i]) {
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({ temperatures[i], i });
        }
        return ans;
    }
};

int main(){
    return 0;
}