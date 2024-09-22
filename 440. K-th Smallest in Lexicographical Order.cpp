#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    long CountST(long left, long right, long n) {
        long count = 0;
        while (left < n) {
            count += min(n - left, right - left);
            left *= 10;
            right *= 10;
        }
        return count;
    }

public:
    int findKthNumber(long n, long k) {
        long count = 1, currPre = 1;
        while (count < k) {
            long stCount = CountST(currPre, currPre + 1, n);
            if (stCount + count < k) {
                count += stCount;
                currPre++;
            }
            else {
                count++;
                currPre *= 10;
            }
        }
        return currPre;
    }
};

int main() {
    return 0;
}