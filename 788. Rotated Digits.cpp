#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> change = {2, 5, 6, 9}, invalids = {3, 4, 7};

    bool CheckNumber(int i) {
        bool hasChanges = false;
        while (i) {
            int digit = i % 10;
            if (count(invalids.begin(), invalids.end(), digit))
                return false;
            if (count(change.begin(), change.end(), digit))
                hasChanges = true;
            i /= 10;
        }

        return hasChanges;
    }

public:
    int rotatedDigits(int n) { 
        int ans = 0;        
        for (int i = 2; i <= n; i++) {
            if (CheckNumber(i))
                ans++;
        }

        return ans;
    }
};

int main() {
    return 0;
}