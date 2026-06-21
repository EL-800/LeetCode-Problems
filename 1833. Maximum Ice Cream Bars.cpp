#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        sort(costs.begin(), costs.end());        
        for (int i : costs) {            
            if (coins - i < 0)
                break;
            coins -= i;
            ans++;
        }
        return ans;
    }
};

int main() {
    return 0;
}