#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length(), left = 0, oneCount = 0;
        string ans;

        for (int right = 0; right < n; right++) {
            oneCount += s[right] == '1';            

            while (oneCount > k) {
                oneCount -= s[left] == '1';
                left++;
            }

            while (oneCount == k && s[left] == '0')
                left++;

            if (oneCount == k) {
                int size = right - left + 1;
                string curr = s.substr(left, size);
                if (ans.empty() || curr.size() < ans.size() || (curr.size() == ans.size() && curr < ans)) 
                    ans = curr;                
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}