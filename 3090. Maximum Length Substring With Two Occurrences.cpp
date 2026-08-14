#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int bucket[26];
        int left = 0, ans = 0;

        for (int right = 0; right < s.length(); right++) {
            bucket[s[right] - 'a']++;
            while (bucket[s[right] - 'a'] > 2) {
                bucket[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    return 0;
}