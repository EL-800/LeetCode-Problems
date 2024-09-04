#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<vector<int>> mappedObs(obstacles.begin(), obstacles.end());
        vector<int> currPos(2, 0);
        int ans = 0, direction = 0;
        for(auto command : commands) {
            if(command == -2) 
                direction = direction - 1 < 0 ? moves.size() - 1 : direction - 1;                                            
            else if(command == -1)
                direction = (direction + 1) % moves.size();            
            while(command-- > 0) {
                vector<int> next = currPos;
                next[0] += moves[direction].first;
                next[1] += moves[direction].second;                
                if(!mappedObs.count(next))
                    currPos = next;
                ans = max(ans, currPos[0] * currPos[0] + currPos[1] * currPos[1]);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}