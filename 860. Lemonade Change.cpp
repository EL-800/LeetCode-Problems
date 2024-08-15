#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {        
        vector<int> billCount(4);
        for(int bill : bills) {                   
            billCount[bill / 5 - 1]++;            
            bill -= 5;
            int requiredTens = bill / 10, avTens = min(requiredTens, billCount[1]);            
            bill -= avTens * 10;
            billCount[1] -= avTens;
            int requiredFives = bill / 5, avFives = min(requiredFives, billCount[0]);
            bill -= avFives * 5;
            billCount[0] -= avFives;
            if (bill)
                return false;            
        }
        return true;
    }
};

int main() {
    vector<int> c = {5,5,10,10,20};
    Solution s;
    s.lemonadeChange(c);
    return 0;
}