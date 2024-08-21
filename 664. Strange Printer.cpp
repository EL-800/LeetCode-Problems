#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
     void shorten(string& s, int& n){
        int sz=s.size();
        n=1;
        // Use 2 pointer to remove successive duplicates
        char cur;
        for(int l=0, r=1; r<sz; r++){
            cur=s[r];
            while(l<r && s[l]==cur) l++;
            if (r<sz && s[l]!=cur){
                s[n++]=s[r];
                l=r;
            }
        }
        s.resize(n);// s is shortened
    //    cout<<s<<endl;
    }

    int dp(vector<vector<int>> &memo, string &s, int left, int right) {
        if (memo[left][right] != -1)
            return memo[left][right];
        if(left == right)
            return 1;
        if(s[left] == s[right])
            return dp(memo, s, left, right - 1);
        int ans = dp(memo, s, left, right - 1) + 1;
        for(int pivot = left + 1; pivot < right - 1; pivot++) {        
            if (s[pivot] == s[right])
                ans = min(ans, dp(memo, s, left, pivot - 1) + dp(memo, s, pivot, right - 1));                        
        }
        return memo[left][right] = ans;
    }

public:
    int strangePrinter(string s) {
        int n = 0;
        shorten(s, n);
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dp(memo, s, 0, n - 1);
    }
};

int main() {
    return 0;
}