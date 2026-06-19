#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAltitude = 0, ans = 0;

        for (int g : gain) {
            currAltitude += g;
            ans = max(ans, currAltitude);
        }

        return ans;
    }
};

int main() {
    return 0;
}