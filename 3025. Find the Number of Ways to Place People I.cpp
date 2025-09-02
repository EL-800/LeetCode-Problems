#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int minY = INT_MAX;
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] > points[j][1])
                    continue;
                if (points[j][1] >= minY)
                    continue;
                minY = min(minY, points[j][1]);
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}