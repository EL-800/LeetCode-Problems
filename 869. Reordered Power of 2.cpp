#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<char, int> DigitCount(int num) {
        unordered_map<char, int> count;
        while (num) {            
            count[num % 10]++;
            num /= 10;
        } 
        return count;
    }

public:
    bool reorderedPowerOf2(int n) {        
        unordered_map<char, int> nCount = DigitCount(n);        
        int currPower = 1;
        while (currPower <= 1e9) {
            unordered_map<char, int> currCount = DigitCount(currPower);            
            if (nCount == currCount)
                return true;
            currPower <<= 1;
        }
        return false;
    }
};

int main() {
    return 0;
}