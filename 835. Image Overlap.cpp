#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int ShiftImg(int r, int c, vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), row2 = 0, col2 = 0, left = 0, right = 0;
        for (int i = r; i < n; i++) {
            col2 = 0;
            for (int j = c; j < n; j++) {
                if (img1[i][j] == 1 && img1[i][j] == img2[row2][col2])
                    left++;
                if (img1[i][col2] == 1 && img1[i][col2] == img2[row2][j])
                    right++;
                col2++;
            }
            row2++;
        }
        return max(left, right);
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, ShiftImg(i, j, img1, img2));
                ans = max(ans, ShiftImg(i, j, img2, img1));
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}