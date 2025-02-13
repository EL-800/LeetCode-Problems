#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> currValues(nums.begin(), nums.end());
            int ans = 0;
            while (currValues.top() < k) {
                long long num1 = currValues.top();
                currValues.pop();
                long long num2 = currValues.top();
                currValues.pop();
                currValues.push(num1 * 2 + num2);
                ans++;
            }
            return ans;
        }
    };

int main() {
    return 0;
}