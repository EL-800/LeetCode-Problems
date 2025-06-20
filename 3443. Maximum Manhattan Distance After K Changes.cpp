#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int CalculateMaxToObj(string &s, int k, string obj) {
        int ans = 0, curr = 0;
        for (char c : s) {
            if (count(obj.begin(), obj.end(), c)) 
                curr++;
            else if (k) {
                curr++;
                k--;
            }
            else
                curr--;
            ans = max(ans, curr);
        }
        return ans;
    }

public:
    int maxDistance(string s, int k) {
        int maxNE = CalculateMaxToObj(s, k, "NE");
        int maxNW = CalculateMaxToObj(s, k, "NW");
        int maxSE = CalculateMaxToObj(s, k, "SE");
        int maxSW = CalculateMaxToObj(s, k, "SW");
        return max({maxNE, maxNW, maxSE, maxSW});
    }
};

int main() {
    return 0;
}