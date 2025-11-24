#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int curr = 0;
        vector<bool> ans;
        for (int num : nums) {
            curr = (curr * 2 + num) % 5;
            ans.push_back(curr == 0);
        }
        return ans;
    }
};

int main() {
    return 0;
}