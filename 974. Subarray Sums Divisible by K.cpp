#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int currSum = 0, res = 0;
        vector<int> modCount(k);               
        modCount[0] = 1;      
        for (int num : nums) {
            currSum +=num;
            currSum = (currSum % k + k) % k;
            res += modCount[currSum]++;
        }
        return res;
    }
};

int main(){
    return 0;
}