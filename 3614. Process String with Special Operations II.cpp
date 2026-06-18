#include <bits/stdc++.h>

using namespace std;

class Solution {    
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> sizes;
        
        long long currSize = 0;
        for (auto c : s) {
            if (c == '*')
                currSize = max(currSize - 1, 0ll);
            else if (c == '#')
                currSize *= 2;
            else if (c != '%')
                currSize++;

            sizes.push_back(currSize);
        }

        if (k >= currSize) 
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#' && k >= sizes[i] / 2)
                k -= sizes[i] / 2;
            else if (s[i] == '%')
                k = sizes[i] - 1 - k;
            else if (s[i] != '*' && sizes[i] == k + 1)
                return s[i];                        
        }

        return '8';
    }
};

int main() {
    return 0;
}