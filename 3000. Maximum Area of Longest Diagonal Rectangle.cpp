#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int longestDiagonal = 0, longestArea = 0;
        for (auto dimension : dimensions) {
            int diagonal = dimension[0] * dimension[0] + dimension[1] * dimension[1];            
            if (diagonal == longestDiagonal) 
                longestArea = max(longestArea, dimension[0] * dimension[1]);                                        
            if (diagonal > longestDiagonal) {
                longestDiagonal = diagonal;
                longestArea = dimension[0] * dimension[1];
            }
        }
        return longestArea;
    }
};

int main() {
    return 0;
}