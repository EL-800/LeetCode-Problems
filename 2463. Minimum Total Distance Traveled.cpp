#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const long long inf = (long long)1e12; 
    int n, m; 
    vector<vector<long long>> memo;    

    long long DP(vector<int> &robot, vector<vector<int>> &factory, int robotInd = 0, int factoryInd = 0) {
        if (robotInd >= n)
            return 0;
        if (factoryInd >= m)
            return inf;
        if (memo[robotInd][factoryInd] != inf)
            return memo[robotInd][factoryInd];
        memo[robotInd][factoryInd] = DP(robot, factory, robotInd, factoryInd + 1);
        long long currDis = 0;
        for (int i = robotInd; i < n && i - robotInd + 1 <= factory[factoryInd][1]; i++) {
            currDis += abs(robot[i] - factory[factoryInd][0]);
            memo[robotInd][factoryInd] = min(memo[robotInd][factoryInd], DP(robot, factory, i + 1, factoryInd + 1) + currDis);
        }
        return memo[robotInd][factoryInd];
    }

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) { 
        n = robot.size(), m = factory.size();    
        memo.assign(n, vector<long long>(m, inf));   
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        return DP(robot, factory);
    }
};

int main() {
    return 0;
}