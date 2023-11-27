#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const long long mod = (long long)1e9 + 7; 
    int reverse(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> op;
        for (int num : nums)
            op[num - reverse(num)]++;
        long long ans = 0;
        for (auto val : op){
            long long q = (long long)val.second;
            ans += (q * (q - 1) / 2) % mod;            
        }                
        return (int)ans;
    }
};

int main(){
    return 0;
}