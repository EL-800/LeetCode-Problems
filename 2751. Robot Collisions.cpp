#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> robots;        
        for (int i = 0; i < n; i++) 
            robots.push_back({positions[i], healths[i], directions[i], i});
        sort(robots.begin(), robots.end());
        stack<vector<int>> currAliveRobots;
        map<int, int> preAns;
        for (auto robot : robots) {            
            if (robot[2] == 'R')
                currAliveRobots.push(robot);
            else {
                while (!currAliveRobots.empty() && robot[1] > currAliveRobots.top()[1]) {
                    robot[1]--;
                    currAliveRobots.pop();
                }
                if (currAliveRobots.empty()) 
                    preAns[robot[3]] = robot[1];                
                else if (robot[1] == currAliveRobots.top()[1])
                    currAliveRobots.pop();
                else {
                    auto top = currAliveRobots.top();
                    currAliveRobots.pop();
                    top[1]--;
                    currAliveRobots.push(top);
                }                                    
            }
        }
        while (!currAliveRobots.empty()) {
            auto curr = currAliveRobots.top();
            currAliveRobots.pop();
            preAns[curr[3]] = curr[1];
        }
        vector<int> ans;
        for (auto robot : preAns)
            ans.push_back(robot.second);
        return ans;
    }
};

int main() {
    vector<int> a = {5,4,3,2,1}, b = {2,17,9,15,10};
    Solution s;
    s.survivedRobotsHealths(a, b, "RRRRR");
    return 0;
}