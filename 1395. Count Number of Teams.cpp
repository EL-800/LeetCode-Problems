#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int left = 0, right = 0;
            for (int j = i - 1; j >= 0; j--) 
                left += rating[j] < rating[i];
            for (int j = i + 1; j < n; j++) 
                right += rating[j] > rating[i];            
            ans += left * right;
            ans += (i - left) * (n - i - 1 - right);
        }
        return ans;
    }
};

int main() {
    return 0;
}