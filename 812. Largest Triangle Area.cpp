#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ans = max(abs((points[j][0] - points[i][0]) * (points[k][1] - points[i][1]) - 
                    (points[j][1] - points[i][1]) * (points[k][0] - points[i][0])) * 0.5, ans);
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}