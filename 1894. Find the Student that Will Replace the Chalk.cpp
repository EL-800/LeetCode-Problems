#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long lK = (long long)k;
        long long totalSum = 0;
        for (auto i : chalk)
            totalSum += (long long)i;
        lK %= totalSum;
        for (int i = 0; i < chalk.size(); i++) {
            lK -= chalk[i];
            if (lK < 0)
                return i;
        }
        return 800;                
    }
};

int main() {
    return 0;
}