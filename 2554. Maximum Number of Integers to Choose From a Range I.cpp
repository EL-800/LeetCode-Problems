#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0, sum = 0;
        unordered_set<int> bannedCount(banned.begin(), banned.end());        
        for (int i = 1; i <= n && sum < maxSum; i++) {
            if (!bannedCount.count(i)) {
                count++;
                sum += i;
            }
        }
        return count;
    }
};

int main() {
    return 0;
}