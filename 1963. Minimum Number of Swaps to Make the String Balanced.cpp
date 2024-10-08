#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<int> opens;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '[')
                opens.push(i);
        }
        int balance = 0, ans = 0; 
        for (int i = 0; i < n; i++) {
            if (s[i] == '[')
                balance++;
            else if (s[i] == ']')
                balance--;
            if (balance < 0) {
                swap(s[i], s[opens.top()]);                
                opens.pop();                
                ans++;
                balance = 1;
            }
        }
        return ans;            
    }
};

int main() {
    return 0;
}