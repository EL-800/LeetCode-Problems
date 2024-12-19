#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        multiset<int> pendigs(arr.begin(), arr.end());
        int chunks = 1, currMax = 0;
        for (int num : arr) {
            pendigs.erase(num);
            if (!currMax)
                currMax = num;
            if (!pendigs.empty() && currMax <= *pendigs.begin()) {
                currMax = 0;
                chunks++;
            }
            else {
                currMax = max(currMax, num);
            }
        }
        return chunks;
    }
};

int main() {
    return 0;
}