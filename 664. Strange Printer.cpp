#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
     void shorten(string& s, int& n){
        int sz=s.size();
        n=1;        
        char cur;
        for(int l=0, r=1; r<sz; r++){
            cur=s[r];
            while(l<r && s[l]==cur) l++;
            if (r<sz && s[l]!=cur){
                s[n++]=s[r];
                l=r;
            }
        }
        s.resize(n);    
    }

    int dp(vector<vector<int>> &memo, string &s, int left, int right) {       
        if(left == right)
            return 1;
         if (memo[left][right] != -1)
            return memo[left][right];
        if(s[left] == s[right])
            return memo[left][right] = dp(memo, s, left, right - 1);        
        for(int pivot = left; pivot < right - 1; pivot++) {        
            if (s[pivot] == s[right])
                memo[left][right] = min(memo[left][right], dp(memo, s, left, pivot - 1) + dp(memo, s, pivot, right - 1));                        
        }
        return memo[left][right];
    }

public:
    int strangePrinter(string s) {
        int n = 0;
        shorten(s, n);
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        return dp(memo, s, 0, n - 1);
    }
};
int main() {
    return 0;
}