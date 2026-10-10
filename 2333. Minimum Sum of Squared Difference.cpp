#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    long long totalK;

    bool IsPossible(vector<int> &diff, int mid) {
    long long operations = 0;
        for (int d : diff) 
            operations += max(0, d - mid);     
        return operations <= totalK;
    }

public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long total = 0;
        int n = nums1.size(), maxDiff = 0;
        totalK = k1 + k2;
        vector<int> diff(n);                
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);  
            total += diff[i];          
            maxDiff = max(maxDiff, diff[i]);
        }        

         if (total <= totalK) 
            return 0;

        int left = 0, right = maxDiff;
        while (left < right) {
            int mid = (left + right) / 2;            
            if (IsPossible(diff, mid)) 
                right = mid;
             else 
                left = mid + 1;            
        }
        
        int validDiff = left;        
        for (int d : diff) 
            totalK -= max(0, d - validDiff);        

        long long result = 0;
        for (int d : diff) {
            d = min(d, validDiff);
            if (d == validDiff && totalK > 0) {
                d--;
                totalK--;
            }
            result += 1LL * d * d;
        }

        return result;
    }
};

int main() {
    return 0;
}