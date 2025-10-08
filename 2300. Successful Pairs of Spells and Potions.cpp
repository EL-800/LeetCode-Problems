#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());        
        vector<int> ans;
        for (int currSpell : spells) {
            auto ind = lower_bound(potions.begin(), potions.end(), success, [currSpell](int curr, long long objective) {
                    return (long long)curr * (long long)currSpell < objective;
                }
            );
            ans.push_back(int(potions.end() - ind));
        }
        return ans;
    }
};


int main() {
    return 0;
}