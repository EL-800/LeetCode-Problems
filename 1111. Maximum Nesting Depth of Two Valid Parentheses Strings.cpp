#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depht = 0, n = seq.length();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                depht++;
                ans[i] = depht % 2;                
            }                
            else {
                ans[i] = depht % 2;
                depht--;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}