#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string removeLeadingZeros(string s){
        int i = 0;
        while (s[i] == '0' && i < s.length()){
            i++;
        }
        return s.substr(i);
    }
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        for (int i = 0; i < n; i++){
            while (!st.empty() && k && num[i] > st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (!st.empty() && k){
            st.pop();
            k--;
        }
        string aux;
        while (!st.empty()){
            aux += st.top();
            st.pop();
        } 
        reverse(aux.begin(), aux.end());
        string ans = removeLeadingZeros(aux);
        return ans != "" ? ans : "0";       
    }
};

int main(){
    Solution s;
    cout << s.removeKdigits("10200", 1);
    return 0;
}