#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> count(3);
        for (int stone : stones)
            count[stone % 3]++;

        if (count[0] % 2 == 0)
            return min(count[1], count[2]) >= 1;

        return abs(count[2] - count[1]) >= 3;
    }
};

int main() {
    return 0;
}