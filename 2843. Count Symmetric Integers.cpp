#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int ans = 0;
            for (int i = low; i <= high; i++) {
                int size = (int) log10 ((double) i) + 1;
                if (size % 2)
                    continue;
                int left = 0, right = 0, mid = size / 2, curr = i;
                while (mid--) {
                    right += curr % 10;
                    curr /= 10;
                }
                mid = size / 2;
                while (mid--) {
                    left += curr % 10;
                    curr /= 10;
                }
                ans += left == right;
            }
            return ans;
        }
    };

int main() {
    return 0;
}