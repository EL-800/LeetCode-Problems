#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            int n = (int)weights.size();
            priority_queue<int, vector<int>, greater<int>> greatest;
            priority_queue<int, vector<int>, less<int>> smallest;        
            for (int i = 0; i < n - 1; i++) {
                int curr = weights[i] + weights[i + 1];
                greatest.push(curr);
                smallest.push(curr);
                if (greatest.size() > k - 1) {
                    greatest.pop();
                    smallest.pop();
                }
            }
            long long maxScore = 0, minScore = 0;
            while (!greatest.empty()) {
                maxScore += greatest.top();
                greatest.pop();
                minScore += smallest.top();
                smallest.pop();            
            }
            return maxScore - minScore;
        }
    };

int main() {
    return 0;
}