#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int zeros = 0, ones = 0;
        for (char c : s){
            if (c == '1')
                ones++;
        }   
        int best = 0;         
        for (int i = 0; i < n - 1; i++){
            if (s[i] == '0')
                zeros++;
            else
                ones--;
            best = max(zeros + ones, best);
        }
        return best;
    }
};

int main(){
    return 0;
}