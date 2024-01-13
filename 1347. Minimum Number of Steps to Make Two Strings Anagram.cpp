#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> countS(26), countT(26);
        for (int i = 0; i < s.length(); i++){
            countS[s[i] - 'a']++;
            countT[t[i] - 'a']++;
        }
        int diff = 0;
        for (int i = 0; i < countS.size(); i++)             
            diff += abs(countS[i] - countT[i]);               
        return diff / 2;
    }
};

int main(){
    Solution s;
    cout << s.minSteps("aba", "bab");
}