#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9 * num < sum)
            return "";
        
        string ans(num, '0');
        int i = 0;
        while (sum) {            
            if (sum < 9) {
                ans[i++] = sum + '0';
                break;
            }
            sum -= 9;
            ans[i++] = '9';
        }        
                
        return ans;
    }
};

int main() {
    return 0;
}