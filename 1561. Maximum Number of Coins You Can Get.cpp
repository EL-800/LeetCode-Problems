#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> piles) {
        sort(piles.begin(), piles.end());
        int left = 0, right = piles.size() - 2, ans = 0;
        while(left < right){
            left++;
            ans += piles[right];
            right -= 2;
        }
        return ans;
    }
};

int main(){

}