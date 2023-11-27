#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> countNum;
        for (int num : nums)
            countNum[num]++;
        int countOp = 0;
        for (auto i = countNum.rbegin(); i != next(countNum.rend(), - 1); i++){
            countOp += i->second;
            next(i, 1)->second += i->second;
        }
        return countOp;
    }
};

int main(){
    Solution s;
    vector<int> c = {1,1,2,2,3};
    cout << s.reductionOperations(c);
    return 0;
}