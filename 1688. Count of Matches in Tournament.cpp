#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        if (n == 1)
            return 0;
        if (!(n % 2))
            return n / 2 + numberOfMatches(n / 2);
        return n / 2 + numberOfMatches(n / 2 + 1);        
    }
};

int main(){

}