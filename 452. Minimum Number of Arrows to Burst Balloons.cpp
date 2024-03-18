#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {                
        sort(points.begin(), points.end());
        int currEnd = points[0][1], shots = 0;
        for (int i = 1; i < points.size(); i++){
            auto range = points[i];
            if (range[0] <= currEnd)
                currEnd = min(currEnd, range[1]);
            else{
                shots++;
                currEnd = range[1];
            }                            
        }
        return shots + 1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main(){
    return 0;
}