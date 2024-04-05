#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;     
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (!st.empty() && islower(st.top()) && toupper(st.top()) == s[i])
                st.pop();
            else if (!st.empty() && isupper(st.top()) && tolower(st.top()) == s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    return 0;
}