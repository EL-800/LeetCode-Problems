#include <bits/stdc++.h>

using namespace std;

class Solution {    
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixesArr1;
        for (int num : arr1) {            
            while (num) {
                prefixesArr1.insert(num);
                num /= 10;
            }
        }
        int ans = 0;
        for (int num : arr2) {
            while (num) {
                if (prefixesArr1.count(num)) {
                    ans = max(ans, (int)log10(num) + 1);
                    break;
                }
                num /= 10;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}