#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length() - 1, c = s.length();        
        while (l < r){                        
            if (s[l] != s[r])
                break;
            char let = s[l];
            int currC = 0;
            while (l <= r && s[l] == let){
                currC++;
                l++;
            }
            while (r >= l && s[r] == let){ 
                r--;
                currC++;
            }          
            c -= currC;
        }
        return c;
    }
};

int main(){
    Solution s;
    s.minimumLength("cabaabac");
    return 0;
}