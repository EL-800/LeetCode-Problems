#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearX = clamp(xCenter, x1, x2) - xCenter,
            nearY = clamp(yCenter, y1, y2) - yCenter;

        return nearX * nearX + nearY * nearY <= radius * radius;
    }
};

int main() {
    return 0;
}