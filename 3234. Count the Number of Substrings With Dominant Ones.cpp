#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> zeroesInd;        
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                zeroesInd.push_back(i);
        }

        zeroesInd.push_back(n);

        int startZero = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int limit = sqrt(n) + 1;            
            for (int j = startZero; j < zeroesInd.size() - 1 && limit; j++, limit--) {
                int zeroes = j - startZero + 1, ones = zeroesInd[j] - i - (j - startZero);;                                 
                if (ones >= zeroes * zeroes) 
                    ans += zeroesInd[j + 1] - zeroesInd[j];
                else 
                    ans += max(zeroesInd[j + 1] - zeroesInd[j] - (zeroes * zeroes - ones), 0);                
            }
            if (s[i] == '0')
                startZero++;
            else 
                ans += zeroesInd[startZero] - i;

        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.numberOfSubstrings("101101");
    return 0;
}