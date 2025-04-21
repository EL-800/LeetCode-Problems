#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long minVal = 0, maxVal = 0, currVal = 0;
            for (int diff: differences) {
                currVal += diff;
                minVal = min(minVal, currVal);
                maxVal = max(maxVal, currVal);
            }
            return max((upper - lower + 1) - (maxVal - minVal), 0l);             
        }
    };

int main() {
    return 0;
}