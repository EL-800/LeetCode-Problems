#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> times(n);
        
        for (int i = 0; i < m; i++) {
            long long potion = mana[i], now = times[0];
            for (int j = 1; j < n; j++) {
                long long mage = skill[j - 1];
                now = max(now + mage * potion, times[j]);
            }
            times[n - 1] = now + skill[n - 1] * potion;
            for (int j = n - 2; j >= 0; j--) {
                long long mage = skill[j + 1];
                times[j] = times[j + 1] - mage * potion; 
            }
        }
        return times.back();
    }
};

int main() {
    return 0;
}