#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> sNums;
        for (int num : nums)
            sNums.push_back(to_string(num));
        sort(sNums.begin(), sNums.end(), [](string &a, string &b) {            
            return a + b > b + a;
        });
        string ans;
        for (auto sNum : sNums)
            ans += sNum;
        int i = 0;
        for (; i < sNums.size() - 1 && ans[i] == '0'; i++) {}        
        return ans.substr(i);
    }
};

int main() {
    return 0;
}