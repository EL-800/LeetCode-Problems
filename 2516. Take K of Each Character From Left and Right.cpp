#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {        
        int n = s.length(), left = 0, right = n - 1, ans = n;
        vector<int> charFrq(3);
        while (left < n) {
            charFrq[s[left] - 'a']++;
            left++;
        }
        if (any_of(charFrq.begin(), charFrq.end(), [&k](const int &e) { return e < k; }))
            return -1;
        left = right;
        while (left >= 0) {
            charFrq[s[left] - 'a']--;
            left--;
            while (right >= left && any_of(charFrq.begin(), charFrq.end(), [&k](const int &e) { return e < k; })) {                
                charFrq[s[right] - 'a']++;
                right--;
            }
            ans = min(ans, left + (n - right));
        }
        return ans;
    }
};

int main() {
    return 0;
}