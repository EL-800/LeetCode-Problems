#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> opens;        
        map<char, char> equivalents = { {'(', ')'}, {'[', ']'}, {'{', '}'} };
        if (s.length() == 1)
            return false;
        for (char curr : s) {
            if (curr == '(' || curr == '[' || curr == '{')
                opens.push(curr);
            else if (!opens.empty() && curr == equivalents[opens.top()])
                opens.pop();
            else
                return false;
        }
        return opens.empty();
    }
};

int main() {
    return 0;
}