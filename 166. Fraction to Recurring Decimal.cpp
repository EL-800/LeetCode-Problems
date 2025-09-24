#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;

        if (numerator == 0)
            return "0";                
        if ((numerator < 0) ^ (denominator < 0))
            ans += "-";        

        long long lNumerator = llabs((long long)numerator);
        long long lDenominator = llabs((long long)denominator);
        ans += to_string(lNumerator / lDenominator);
        long long remainder = lNumerator % lDenominator;

        if (!remainder) 
            return ans;        
        ans += ".";
        unordered_map<long long, int> reminderCount;
        while (remainder) {
            if (reminderCount.count(remainder)) {
                ans.insert(reminderCount[remainder], "(");
                ans += ")";
                break;
            }
            reminderCount[remainder] = ans.size();
            remainder *= 10;
            ans += to_string(remainder / lDenominator);
            remainder %= lDenominator;
        }

        return ans;
    }
};

int main() {
    return 0;
}