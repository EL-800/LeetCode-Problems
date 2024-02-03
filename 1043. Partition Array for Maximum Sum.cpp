#include <bits/stdc++.h>

using namespace std;

class Solution {    
private:
    vector<int> memo;

    int dp(vector<int>& arr, int k, int currInd = 0){   
        if (currInd >= arr.size())
            return 0;     
        if (memo[currInd] != -1)
            return memo[currInd];
        int currBest = 0, currMax = 0;
        for (int i = 0; i < k && i + currInd < arr.size(); i++){
            currMax = max(currMax, arr[currInd + i]);
            currBest = max(currBest, dp(arr, k, currInd + i + 1) + currMax * (i + 1));
        }
        return memo[currInd] = currBest;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memo.assign(arr.size(), -1);
        return dp(arr, k);
    }
};

int main(){
    return 0;
}