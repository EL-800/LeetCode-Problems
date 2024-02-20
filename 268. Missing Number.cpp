#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = 0;
        for (int i : nums) sum += i;
        int theory = n * (n + 1) / 2;
        return theory - sum;
    }
};

int main(){
    return 0;
}