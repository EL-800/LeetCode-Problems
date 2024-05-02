#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> seen;
        int maximum = -1;
        for (int num : nums){
            if (seen.count(num * -1))
                maximum = max(maximum, abs(num));
            seen.insert(num);
        }
        return maximum;
    }
};

int main(){
    return 0;
}