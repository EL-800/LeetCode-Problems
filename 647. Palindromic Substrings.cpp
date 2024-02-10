#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int FindSubstrings(string& s, vector<bool>& begins, int size) {
        int n = (int)s.size(), curr = 0;
        for (int i = 0; i < n; i++) {
            int j = i + size - 1;
            if (j >= n)
                begins[i] = false;
            else if (s[i] == s[j] && begins[i + 1]) {
                begins[i] = true;
                begins[i + 1] = false;
                curr++;
            }
            else {
                begins[i] = false;
                begins[i + 1] = false;
            }
        }
        return curr;
    }
public:
    int countSubstrings(string s) {
        int n = (int)s.size(), ans = 0;
        vector<bool> even(n + 2, 1);
        vector<bool> odd(n + 2, 1);
        for (int i = 1; i <= n; i++) {
            if (i % 2)
                ans += FindSubstrings(s, even, i);
            else
                ans += FindSubstrings(s, odd, i);
        }
        return ans;
    }
};

int main(){
    return 0;
}