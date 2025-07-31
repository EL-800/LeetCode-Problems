#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> nextAvilableBit(n, vector<int>(32, n));
        for (int i = n - 1; i >= 0; i--) {
            nextAvilableBit[i] = (i + 1 == n) ?  vector<int>(32, n) : nextAvilableBit[i + 1];
            int bitInd = 0;
            while ((1 << bitInd) <= arr[i]) {
                if ((1 << bitInd) & arr[i])
                    nextAvilableBit[i][bitInd] = i;
                bitInd++;
            }                
        } 
        unordered_set<int> seenNums;       
        for (int i = 0; i < n; i++) {
            int currNum = 0, j = i;
            while (j < n) {
                currNum |= arr[j];
                seenNums.insert(currNum);
                int nextJ = INT_MAX;
                for (int bitInd = 0; bitInd < 32; bitInd++) {
                    if ((1 << bitInd) & currNum)
                        continue;
                    nextJ = min(nextJ, nextAvilableBit[j][bitInd]);
                }
                j = nextJ;
            }
        }
        return seenNums.size();
    }
};

int main() {
    return 0;
}