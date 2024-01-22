#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> bucket(n + 1);
        for (int i : nums)
            bucket[i]++;
        vector<int> ans(2);
        for (int i = 1; i <= n; i++) {
            if (!bucket[i])
                ans[1] = i;
            if (bucket[i] == 2)
                ans[0] = i;
        }
        return ans;
    }
};

int main(){
    return 0;
}