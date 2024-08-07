#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> post = {"",        "One",     "Two",       "Three",    "Four",
                "Five",    "Six",     "Seven",     "Eight",    "Nine",
                "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
                "Twenty",  "Thirty",  "Forty",     "Fifty",    "Sixty",
                "Seventy", "Eighty",  "Ninety",    "Hundred",  "Thousand",
                "Million", "Billion"};
                
    vector<int> num = {0,  1,  2,  3,  4,  5,  6,   7,    8,       9,         10,
               11, 12, 13, 14, 15, 16, 17,  18,   19,      20,        30,
               40, 50, 60, 70, 80, 90, 100, 1000, 1000000, 1000000000};

public:
    string numberToWords(int curr, int cnt=0) {
        if (curr == 0) 
            return cnt==0 ? "Zero" : "";
        if (curr <= 20) 
            return post[curr];
        int i = upper_bound(num.begin(), num.end(), curr) - num.begin() - 1;
        auto [q, r] = div(curr, num[i]);
        string ans = "";
        if (num[i]>=100)
            ans += numberToWords(q, cnt+1) + " " + post[i];
        else 
            ans = post[i];
        if (r>0) 
            ans += " " + numberToWords(r, cnt+1);        
        return ans;
    }
};

int main() {
    return 0;
}