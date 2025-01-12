#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        stack<int> open, unlocked;    
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0')
                unlocked.push(i);
            else if (s[i] == '(')
                open.push(i);
            else {
                if (!open.empty())
                    open.pop();
                else if (!unlocked.empty())
                    unlocked.pop();
                else
                    return false;
            }            
        }
        while (!open.empty() && !unlocked.empty() && open.top() < unlocked.top()) {
            open.pop();
            unlocked.pop();            
        }

        if (open.empty()) 
            return !(unlocked.size() % 2);        
        return false;
    }
};

int main() {
    return 0;
}