#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> accesible(n);
        for (int box : initialBoxes)
            accesible[box] = true;

        bool change = false;
        int ans = 0;

        do {
            change = false;
            for (int i = 0; i < n; i++) {
                if (accesible[i] && status[i]) {
                    ans += candies[i];
                    for (int key : keys[i])
                        status[key] = true;
                    for (int box : containedBoxes[i])
                        accesible[box] = true;                        
                    accesible[i] = false; 
                    change = true;
                }
            }
        } while (change);

        return ans;
    }
};

int main() {
    return 0;
}