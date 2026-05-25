#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(string &s, int minJump, int maxJump) {
        int n = s.length(), reachable = 0;
        vector<int> sweepline(n + 1);
        sweepline[0] = 1;
        sweepline[1] = -1;

        for (int i = 0; i < n; i++) {
            reachable += sweepline[i];

            if (i == n - 1 && s[i] == '0' && reachable)
                return true;

            if (s[i] == '0' && reachable) {
                sweepline[min(i + minJump, n)]++;
                sweepline[min(i + maxJump + 1, n)]--;
            }            
        }

        return false;
    }
};

int main() {
    return 0;
}