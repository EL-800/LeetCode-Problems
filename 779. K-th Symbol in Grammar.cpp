#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int Search(int n, int k){
        if (n == 0)
            return 0;        
        int prev = Search(n - 1, k >> 1) + 1;
        return (prev & (1 << ((k + 1) % 2))) != 0;
    }

public:
    int kthGrammar(int n, int k) {
        return Search(n - 1, k - 1);
    }
};

int main(){
    Solution s;
    cout << s.kthGrammar(2, 2);
    return 0;
}