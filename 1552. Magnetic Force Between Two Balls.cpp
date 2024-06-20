#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool checkMinimumDistance(vector<int>& positions, int m, int distance){
        int lastBall = positions[0], placedBalls = 1;
        for (int i = 1; i < positions.size(); i++) {
            if (lastBall + distance <= positions[i]) {
                placedBalls++;
                lastBall = positions[i];
            }
        }
        return placedBalls >= m;        
    }

public:
    int maxDistance(vector<int>& positions, int m) {        
        sort(positions.begin(), positions.end());
        int left = 0, right = *positions.rbegin() - *positions.begin();
        while (left < right) {
            int mid = (left + right) / 2 + 1;
            if (checkMinimumDistance(positions, m, mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};

int main(){
    vector<int> c = {1,2,3,4,7};
    Solution s;
    cout << s.maxDistance(c, 3);
    return 0;
}