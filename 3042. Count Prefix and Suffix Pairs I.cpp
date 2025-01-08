#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isPrefixAndSuffix(string &str1, string &str2) {
        int n = str1.length(), m = str2.length();
        for (int i = 0; i < n; i++) {
            if (str1[i] != str2[i] || str1[n - i - 1] != str2[m - i - 1])
                return false;
        }
        return true;        
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}