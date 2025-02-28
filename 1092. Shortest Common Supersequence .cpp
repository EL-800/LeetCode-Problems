#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        vector<vector<int>> memo;
    
        int DP(string &str1, string &str2, int ind1 = 0, int ind2 = 0) {
            if (ind1 == str1.length() || ind2 == str2.length())
                return 0;
            if (memo[ind1][ind2] != -1)
                return memo[ind1][ind2];
            if (str1[ind1] == str2[ind2])
                return memo[ind1][ind2] = DP(str1, str2, ind1 + 1, ind2 + 1) + 1;
            return memo[ind1][ind2] = max(DP(str1, str2, ind1 + 1, ind2), DP(str1, str2, ind1, ind2 + 1));
        }

    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int n = str1.length(), m = str2.length();
            memo.assign(n, vector<int>(m, -1));
            DP(str1, str2);            
            int ind1 = 0, ind2 = 0;
            string ans;
            while (ind1 < n && ind2 < m) {
                if (str1[ind1] == str2[ind2]) {
                    ans += str1[ind1];
                    ind1++;
                    ind2++;
                }
                else if (DP(str1, str2, ind1 + 1, ind2) > DP(str1, str2, ind1, ind2 + 1)) {
                    ans += str1[ind1];
                    ind1++;
                }
                else {
                    ans += str2[ind2];
                    ind2++;
                }                
            }
            while (ind1 < n) {
                ans += str1[ind1];
                ind1++;
            }
            while (ind2 < m) {
                ans += str2[ind2];
                ind2++;
            }
            return ans;
        }
    };

int main() {
    return 0;
}