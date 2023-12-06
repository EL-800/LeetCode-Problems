#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {        
        int weekN = n / 7, ans = (weekN * (weekN - 1) / 2) * 7, ufWeek = n - weekN * 7;
        ans += 28 * weekN;
        ans += ufWeek * (ufWeek + 1) / 2 + ufWeek * weekN;
        return ans;
    }
};

int main(){
    return 0;
}