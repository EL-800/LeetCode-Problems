#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> greatests;
        for (int num : nums)
            greatests.push(num);
        while (k--) {
            int curr = greatests.top();
            greatests.pop();
            ans += (long long)curr;
            greatests.push(ceil((double)curr / 3));
        }
        return ans;
    }
};

int main() {
    return 0;
}