#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int yCap(vector<int>& first, vector<int>& second) {        
        return min(second[1], first[1] + abs(second[0] - first[0]));
    }

    int maxBuilding(int num, vector<vector<int>>& restrictions) {        
        restrictions.push_back({1, 0});
        int n = restrictions.size();
        sort(restrictions.begin(), restrictions.end());        

        for (int i = 1; i < n; i++)
            restrictions[i][1] = yCap(restrictions[i - 1], restrictions[i]);

        for (int i = n - 2; i >= 0; i--)
            restrictions[i][1] = yCap(restrictions[i + 1], restrictions[i]);

        int ans = 0;
        for (int i = 1; i < n; i++)
            ans = max(ans, (restrictions[i - 1][1] + restrictions[i][1] + 
                restrictions[i][0] - restrictions[i - 1][0]) / 2);

        return max(ans, restrictions[n - 1][1] + num - restrictions[n - 1][0]);
    }    
};

int main() {
    return 0;
}