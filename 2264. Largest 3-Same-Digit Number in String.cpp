#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string ans;
        for (int i = 2; i < n; i++){
            string curr = num.substr(i - 2, 3);
            if (curr[0] == curr[1] && curr[1] == curr[2])
                ans = max(ans, curr);
        }
        return ans;
    }
};

int main(){
    return 0;
}