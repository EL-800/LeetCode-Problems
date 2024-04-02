#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMapped;
        unordered_set<char> tAvilable;
        for (char i : t)
            tAvilable.insert(i);
        for (int i = 0; i < s.length(); i++){
            if (!sMapped.count(s[i])){
                if (tAvilable.count(t[i])) {
                    sMapped[s[i]] = t[i];
                    tAvilable.erase(t[i]);
                }
                else
                    return false;
            }
            else if (sMapped[s[i]] != t[i])
                return false;
        }
        return true;
    }
};

int main(){
    return 0;
}