#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;
    vector<unordered_map<char, int>> freq;
    vector<vector<int>> dp;
    string target;

    void CalculateFreq(vector<string>& words) {        
        for (string word : words) {
            for (int i = 0; i < (int)word.size(); i++) {
                if ((int)freq.size() <= i)
                    freq.push_back(unordered_map<char, int>());
                freq[i][word[i]]++;
            }
        }
    }

    int CalculateWays(int i = 0, int k = 0) {
        if (i == target.length())
            return 1;
        if (k == (int)freq.size())
            return 0;        
        if (dp[i][k] != -1)
            return dp[i][k];       
        int left = CalculateWays(i, k + 1);
        long long right = 0;
        if (freq[k].find(target[i]) != freq[k].end())
            right = ((long long)freq[k][target[i]] * (long long)CalculateWays(i + 1, k + 1)) % mod;        
        return dp[i][k] = (left + (int)right) % mod;
    }

public:
    int numWays(vector<string>& words, string target) {
        CalculateFreq(words);
        int maxK = freq.size();
        dp.assign(target.length(), vector<int>(maxK + 1, -1));
        this->target = target;
        return CalculateWays() % mod;
    }
};


int main() {
    return 0;
}