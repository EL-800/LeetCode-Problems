#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        bool IsPossible(int obj, int x) {
            if (obj < 0)
                return false;
            if (!x)
                return !obj;
            int digitSum = 0, ind = 0;
            do {
                digitSum += (x % 10) * pow(10, ind);
                ind++;
                if (IsPossible(obj - digitSum, x / 10))
                    return true;                
            } while (x /= 10);
            return false;
        }

    public:
        int punishmentNumber(int n) {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                ans += IsPossible(i, i * i) ? i * i : 0;            
            return ans;
        }
    };

int main() {
    Solution s;
    cout << s.punishmentNumber(10);
    return 0;
}