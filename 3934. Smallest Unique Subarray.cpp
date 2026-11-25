#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const long long base = 100003;
    const long long mod = 1000000007;
    vector<long long> powers;
    vector<long long> hashes;    

    void RollingHash(vector<int>& nums) {
        int n = nums.size();

        hashes.resize(n + 1, 0);
        powers.resize(n + 1, 1);
        
        for (int i = 0; i < n; i++) {
            hashes[i + 1] = (hashes[i] * base + nums[i]) % mod;
            powers[i + 1] = (powers[i] * base) % mod;
        }
    }
    
    long long getHash(int l, int r) {
        return (hashes[r + 1] - hashes[l] * powers[r - l + 1] % mod + mod) % mod;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();             
        RollingHash(nums);

        int left = 1, right = n;  
        unordered_map<long long, int> currArrays; 
        while (left <= right) {
            currArrays.clear();
            int mid = left + (right - left) / 2;            
            
            for (int i = 0; i + mid <= n; i++) {
                long long hash = getHash(i, i + mid - 1);
                currArrays[hash]++;
            }
            
            bool flag = false;
            for (auto &[val, count]: currArrays) {
                if (count == 1) {
                    flag = true;
                    break;
                }
            }

            if (flag) 
                right = mid - 1;
            else 
                left = mid + 1;            
        }

        return left;
    }
};

int main() {
    return 0;
}