#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {            
            int gcd = 0;            
            while (!ans.empty() && (gcd = __gcd(ans.back(), num)) != 1) {                
                int leastMultiple = ans.back() / gcd * num;
                ans.pop_back();
                num = leastMultiple;
            }
            ans.push_back(num);                        
        }
        return ans;
    }
};

int main() {
    return 0;
}