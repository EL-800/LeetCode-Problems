#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int inf = 1e8;
        int n=arr.size();
        vector<int>prefix(n);

        int curr = 0, left = 0, best = inf;
        for(int right = 0; right < n; right++) {
            curr += arr[right];
            while(curr > target) {
                curr -= arr[left];
                left++;
            }
            if(curr == target)
                best = min(best, right - left + 1);
            prefix[right] = best;
        }

        vector<int>suffix(n);
        curr = 0;
        best = inf;
        int right = n - 1;        
        for(int left = n - 1; left >= 0; left--) {
            curr += arr[left];
            while(curr > target) {
                curr -= arr[right];
                right--;
            }
            if(curr == target)
                best=min(best,right-left+1);
            suffix[left]=best;
        }

        int ans = inf;
        for(int i = 0; i < n - 1; i++) {
            if(prefix[i] != inf && suffix[i+1] != inf)
                ans=min(ans, prefix[i] + suffix[i + 1]);
        }
        return ans == inf ? -1 : ans;
    }
};

int main() {
    return 0;
}