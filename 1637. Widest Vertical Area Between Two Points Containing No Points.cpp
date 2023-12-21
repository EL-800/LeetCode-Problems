#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xPoints;
        for (vector<int> point : points)
            xPoints.push_back(point[0]);
        sort(xPoints.begin(), xPoints.end());
        int maxDiff = 0;
        for (int i = 1; i < xPoints.size(); i++)
            maxDiff = max(maxDiff, xPoints[i] - xPoints[i - 1]);
        return maxDiff;
    }
};

int main(){
    return 0;
}