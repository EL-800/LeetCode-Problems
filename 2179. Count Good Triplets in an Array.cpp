#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> nums1Indexes;            
            for (int i = 0; i < nums1.size(); i++) 
                nums1Indexes[nums1[i]] = i;            
            set<int> seenIndexes;
            long long total = 0 , n = nums1.size();            
            for (int i = 0; i < n; i++) {
                int ind = nums1Indexes[nums2[i]];    
                int left = distance(seenIndexes.begin(), seenIndexes.lower_bound(ind));
                int right = (n - 1 - ind) - (seenIndexes.size() - left);
                total += (long long) left * right;
                seenIndexes.insert(ind);
            }
            return total;
        }
    };

int main() {
    return 0;
}