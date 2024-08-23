#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        int totalNumerator = 0, totalDenominator = 1;
        int ind = 0;
        while (ind < expression.size()) {
            int currNumerator = 0;
            int neg = 1;
            if (expression[ind] == '-') {
                neg = -1;
                ind++;
            }
            else if (expression[ind] == '+')
                ind++;
            while (expression[ind] >= '0' && expression[ind] <= '9') {
                currNumerator *= 10;
                currNumerator += expression[ind] - '0';
                ind++;
            }
            currNumerator *= neg;
            ind++;
            int currDenominator = 0;            
            while (ind < expression.size() && expression[ind] >= '0' && expression[ind] <= '9') {
                currDenominator *= 10;
                currDenominator += expression[ind] - '0';
                ind++;
            }
            totalNumerator = totalNumerator * currDenominator + currNumerator * totalDenominator;
            totalDenominator = totalDenominator * currDenominator;
            int gcd = abs(__gcd(totalNumerator, totalDenominator));            
            totalNumerator /= gcd;
            totalDenominator /= gcd;
        }        
        return to_string(totalNumerator) + "/" + to_string(totalDenominator);
    }
};

int main() {
    Solution s;
    s.fractionAddition("-1/2+1/2");
    return 0;
}