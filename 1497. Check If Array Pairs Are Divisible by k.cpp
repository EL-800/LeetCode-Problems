#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int freqCount[k];
        memset(freqCount, 0, sizeof(freqCount));
        for (int i : arr)
            freqCount[((i % k) + k) % k]++;
        if (freqCount[0] % 2)
            return false;
        for (int i = 1; i < k; i++) {
            if (i == k - i) {
                if (freqCount[i] % 2)
                    return false;
                continue;
            }
            if (freqCount[i] != freqCount[k - i])             
                return false;
        }
        return true;        
    }
};

int main() {
    return 0;
}