#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;        
        for(int num : nums) {
            if(num != 2) 
                ans.push_back(num - ((num + 1) & (-num - 1)) / 2);
            else 
                ans.push_back(-1);
        }   
        return ans;
    }
};

int main() {
    return 0;
}