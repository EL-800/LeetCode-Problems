#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length(), opens = 0, add = 0;
        for(int i = 0; i < n; i++) {            
            if (s[i] == '('){
                opens += 2;
                if (opens % 2){
                    add++;
                    opens--;
                }
            }
            else {
                opens--;
                if (opens < 0){
                    add++;
                    opens+=2;
                }               
            }
        }
        return opens + add;
    }
};

int main() {
    return 0;
}