#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums)
            count[num]++;
        
        vector<int> ans;
        for (auto [key, val] : count) {
            if (val == 2)
                ans.push_back(key);
        }
        
        return ans;
    }
};

int main() {
    return 0;
}