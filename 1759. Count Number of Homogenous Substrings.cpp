#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        const int mod = (int)1e9 + 7;
        int count = 1, streak = 1;
        for (int i = 1; i < s.length(); i++){
            if (s[i] == s[i - 1])
                streak++;
            else 
                streak = 1;                
            count = (count + streak) % mod;
        }
        return count % mod;
    }
};

int main(){
    return 0;
}