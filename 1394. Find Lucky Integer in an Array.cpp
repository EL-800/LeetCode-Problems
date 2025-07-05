#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freqCount;
        for (auto num : arr)
            freqCount[num]++;

        int ans = -1;
        for (auto [key, val] : freqCount) {
            if (key == val)
                ans = max(ans, key);
        }
        return ans;
    }
};

int main() {
    return 0;
}