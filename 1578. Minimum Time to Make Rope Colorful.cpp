#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = (int)colors.size();
        for (int i = 0; i < n - 1; i++) {            
            if (colors[i] == colors[i + 1]) {
                int maxi = neededTime[i];
                ans += neededTime[i];
                while (i < n - 1 && colors[i] == colors[i + 1]) {
                    maxi = max(maxi, neededTime[i + 1]);
                    ans += neededTime[i + 1];
                    i++;
                }
                ans -= maxi;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}