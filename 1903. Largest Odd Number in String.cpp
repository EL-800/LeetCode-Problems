#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length(), numStart = 0;
        for (numStart; numStart < n; numStart++)
            if (num[numStart] != '0')
                break;
        vector<char> odds = {'1', '3', '5', '7', '9'};
        for (int i = n - 1; i >= 0; i--)
            if (count(odds.begin(), odds.end(), num[i]))        
                return num.substr(numStart, i - numStart + 1);
        return "";
    }
};

int main(){
    return 0;
}