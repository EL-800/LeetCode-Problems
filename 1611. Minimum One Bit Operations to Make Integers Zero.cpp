#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int currBit = 1;
        stack<int> setBits;
        while (currBit <= n){
            if (currBit & n)
                setBits.push(currBit);
            currBit <<= 1;
        }
        int ans = 0;
        bool sumRestFlag = true;
        while (!setBits.empty()){
            if (sumRestFlag)
                ans += (setBits.top() << 1) - 1;
            else
                ans -= (setBits.top() << 1) - 1;
            setBits.pop();
            sumRestFlag ^= true;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.minimumOneBitOperations(15);
    return 0;
}