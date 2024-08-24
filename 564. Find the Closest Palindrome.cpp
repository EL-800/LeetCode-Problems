#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")

using namespace std;

class Solution {
private:
    static inline bool checkPalindrome(long long n)
    {
        long long reverse = 0;
        // Copy of the original number so that the original
        // number remains unchanged while finding the reverse
        long long temp = n;
        while (temp != 0) {
            reverse = (reverse * 10) + (temp % 10);
            temp = temp / 10;
        }
        // If reverse is equal to the original number, the
        // number is palindrome
        return (reverse == n);
    }

public:
    string nearestPalindromic(string n) {
        long long num = stoll(n), next = num + 1, prev = num - 1;
        while(!checkPalindrome(next) && !checkPalindrome(prev)) {
            next++;                        
            prev--;
        }
        return next - num < num - prev ? to_string(next) : to_string(prev);
    }
};

int main() {
    Solution s;
    cout << s.nearestPalindromic("807045053224792883");
    return 0;
}