#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        bool Check(map<int, int>& sweepLine) {
            int opens = 0, cuts = 0;
            for (auto [ind, val] : sweepLine) {
                opens += val;
                cuts += opens == 0;
            }
            return cuts > 2;
        }


    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            map<int, int> horizontalLine, verticalLine;
            for (auto rectangle : rectangles) {
                horizontalLine[rectangle[0]]++;
                horizontalLine[rectangle[2] - 1]--;
                verticalLine[rectangle[1]]++;
                verticalLine[rectangle[3] - 1]--;
            }
            return Check(horizontalLine) || Check(verticalLine);

        }
    };

int main() {

}