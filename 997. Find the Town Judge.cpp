#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustInHim(n + 1), trustInAnyone(n + 1);
        for (vector<int> i : trust) {
            trustInHim[i[1]]++;
            trustInAnyone[i[0]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (trustInHim[i] == n - 1 && !trustInAnyone[i])
                return i;
        }
        return -1;
    }
};

int main(){
    return 0;
}