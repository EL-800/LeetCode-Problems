#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            const int mod = 1e9 + 7;
            int oddCount = 0, sum = 0, ans = 0;
            for (int i = 0; i < arr.size(); i++) {
                sum += arr[i];
                if (sum % 2)
                    ans = (ans + (i + 1 - oddCount)) % mod;
                else
                    ans = (ans + oddCount) % mod;
                oddCount += sum % 2;               
            }
            return ans % mod;
        }
    };

int main() {
    return 0;
}