#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        long long factorial(int n) {
            return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
        }

    public:
        long long countGoodIntegers(int n, int k) {
            int digit = pow(10, (n - 1) / 2);
            int skip = n % 2;
            unordered_set<string> found;            
    
            for (int i = digit; i < digit * 10; i++) {
                string s = to_string(i), rev = s;
                reverse(rev.begin(), rev.end());
                s += rev.substr(skip);
                long long val = stoll(s);
                if (!(val % k)) {
                    sort(s.begin(), s.end());
                    found.insert(s);
                }
            }                
            long long ans = 0;
            for (string s : found) {
                vector<int> count(10);
                for (char c : s) 
                    count[c - '0']++;
                long long curr = (n - count[0]) * factorial(n - 1);
                for (int c : count) {
                    if (c > 1) curr /= factorial(c);
                }
                ans += curr;
            }
    
            return ans;
        }
    };

int main() {
    return 0;
}