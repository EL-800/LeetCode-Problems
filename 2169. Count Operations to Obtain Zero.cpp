#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 && num2) {
            if (num1 < num2)
                swap(num1, num2);
            int op = num1 / num2;            
            num1 -= op * num2;
            ans += op;
        }
        return ans;
    }
};

int main() {
    return 0;
}