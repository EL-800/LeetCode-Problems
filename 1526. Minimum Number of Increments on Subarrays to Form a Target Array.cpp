#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0, prev = 0;
        for (int curr : target) {
            ans += max(curr - prev, 0);       
            prev = curr;
        }
        return ans;
    }
};

int main() {
    return 0;
}