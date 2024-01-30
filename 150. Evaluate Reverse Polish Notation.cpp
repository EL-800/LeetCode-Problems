#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for (string i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                if (i == "+")
                    s.push(b + a);
                else if (i == "-")
                    s.push(b - a);
                else if (i == "*")
                    s.push(b * a);
                else
                    s.push(b / a);
            }
            else
                s.push((long long)atoi(i.c_str()));
        }
        return s.top();
    }
};

int main(){
    return 0;
}