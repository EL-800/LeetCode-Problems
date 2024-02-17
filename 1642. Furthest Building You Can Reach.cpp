#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> greatestsJumps;        
        int i;
        for (i = 0; i < heights.size() - 1; i++){            
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0)
                continue;
            greatestsJumps.push(diff);
            if (greatestsJumps.size() > ladders) {
                bricks -= greatestsJumps.top();
                if (bricks < 0)
                    break;
                greatestsJumps.pop();
            }            
        }
        return i;
    }
};

int main(){
    vector<int> c = {2,7,9,12};
    Solution s;
    s.furthestBuilding(c, 5, 1);    
    return 0;
}