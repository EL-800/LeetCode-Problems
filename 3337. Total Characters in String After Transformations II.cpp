#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;

    vector<vector<long long>> Multiply(vector<vector<long long>> matrix1, vector<vector<long long>> matrix2) {
        int row1 = matrix1.size(), row2 = matrix2.size(), col1 = matrix1[0].size(), col2 = matrix2[0].size();
        vector<vector<long long>> ans(row1, vector<long long>(col2));
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                for (int c = 0; c < col2; c++) 
                    ans[i][j] = (ans[i][j] + (matrix1[i][c] * matrix2[c][j]) % mod) % mod;
            }
        }
        return ans;
    }

    vector<vector<long long>> Exponentation(vector<vector<long long>> matrix, int t) {
        int n = matrix.size();
        vector<vector<long long>> ans(n, vector<long long>(n));
        for (int i = 0; i < n; i++)
            ans[i][i] = 1;
        while (t) {
            if (t % 2)
                ans = Multiply(ans, matrix);
            matrix = Multiply(matrix, matrix);
            t >>= 1;
        }
        return ans;
    } 

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = 26;
        vector<vector<long long>> matrix(n, vector<long long>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++)
                matrix[i][(i + j) % n]++;            
        }
        matrix = Exponentation(matrix, t);
        vector<vector<long long>> freq(1, vector<long long>(n));
        for (auto c : s)
            freq[0][c - 'a']++;
        freq = Multiply(freq, matrix);
        int ans = 0;
        for (int f : freq[0]) 
            ans = (ans + f) % mod;
        return ans;
    }
};

int main() {
    return 0;
}