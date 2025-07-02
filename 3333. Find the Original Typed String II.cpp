#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        vector<int> groups;
        int count = 1;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1])
                count++;
            else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);

        long total = 1;
        for (int g : groups)
            total = (total * g) % mod;  
            
        if (k <= groups.size()) 
            return total;

        vector<int> memo(k, 0);
        memo[0] = 1;

        for (int g : groups) {
            vector<int> auxMemo(k, 0);
            long sum = 0;
            for (int i = 0; i < k; i++) {
                if (i)
                    sum = (sum + memo[i - 1]) % mod;
                if (i > g)
                    sum = (sum - memo[i - g - 1] + mod) % mod;
                auxMemo[i] = sum;
            }
            memo = auxMemo;
        }

        long invalid = 0;
        for (int s = groups.size(); s < k; s++)
            invalid = (invalid + memo[s]) % mod;

        return (total - invalid + mod) % mod;
    }
};

int main() {
    return 0;
}