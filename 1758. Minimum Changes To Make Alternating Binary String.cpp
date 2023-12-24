#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int bitWiseCount(string s){
        int n = s.length(), count = 0;
        for (int i = 1; i < n; i++){
            if (s[i - 1] == s[i]) {
                count++;
                if (s[i - 1] == '0')
                    s[i] = '1';
                else
                    s[i] = '0';
            }
        }
        return count;
    }

public:
    int minOperations(string s) {
        int left = 0, right = 0;
        if (s[0] == '0') {
            left = bitWiseCount(s);
            s[0] = '1';
            right = bitWiseCount(s) + 1;
        }
        else {
            left = bitWiseCount(s);
            s[0] = '0';
            right = bitWiseCount(s) + 1;
        }            
        return min(left, right);
    }
};

int main(){
    return 0;
}