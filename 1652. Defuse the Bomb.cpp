#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int mK = k, n = code.size();
        if (k == 0)
            return vector<int>(n);
        if (k < 0) {
            reverse(code.begin(), code.end());
            mK *= -1;
        }
        int currSum = accumulate(code.begin() + 1, code.begin() + mK + 1, 0), left = 1, right = mK;  
        vector<int> ans;
        do {
            ans.push_back(currSum);
            currSum -= code[left];
            left = (left + 1) % n;
            right = (right + 1) % n;
            currSum += code[right];
        } while(left != 1);
        if (k < 0)
            reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    return 0;
}