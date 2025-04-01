#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:    
        vector<long long> dp;
    
        long long FindMaxPoints(vector<vector<int>>& questions, int currInd = 0) {
            if (currInd >= (int)questions.size())
                return 0;
            if (dp[currInd] != -1)
                return dp[currInd];
            long long skip = FindMaxPoints(questions, currInd + 1);
            long long take = questions[currInd][0] + FindMaxPoints(questions, currInd + questions[currInd][1] + 1);
            return dp[currInd] = max(skip, take);
        }
    
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            dp.assign(int(questions.size()), -1);
            return FindMaxPoints(questions);
        }
    };

int main() {
    return 0;
}