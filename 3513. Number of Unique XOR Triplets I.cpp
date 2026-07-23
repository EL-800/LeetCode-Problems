#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size(), msb = 1;
        if (n < 3)
            return n;
        while (msb <= n)
            msb <<= 1;
        return msb;
    }
};

int main() {
    return 0;
}