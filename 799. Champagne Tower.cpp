#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int n = 100;
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower;
        for (int i = 0; i < n; i++)
            tower.push_back(vector<double>(i + 1));
        tower[0][0] = (double)poured;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j <= i; j++) {
                if (tower[i][j] > 1) {
                    tower[i][j]--;
                    tower[i + 1][j] += tower[i][j] / 2;
                    tower[i + 1][j + 1] += tower[i][j] / 2;
                    tower[i][j] = 1;
                }
            }
        }
        return tower[query_row][query_glass];
    }
};

int main() {
    return 0;
}