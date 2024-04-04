#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepth = 0;
        for (char i : s){
            if (i == '(')
                depth++;
            else if (i == ')')
                depth--;
            maxDepth = max(maxDepth, depth);
        }
        return maxDepth;
    }
};

int main(){
    return 0;
}