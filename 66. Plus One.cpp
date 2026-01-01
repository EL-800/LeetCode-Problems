#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();          
        for (int i = n - 1; i >= 0; i--) {            
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i])
                break;
        }
        if (!digits[0])            
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    return 0;
}