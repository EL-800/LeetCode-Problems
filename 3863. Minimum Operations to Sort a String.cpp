#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        bool isSorted = 1;
        char smallest = s[0], largest = s[0];        

        for (int i = 1; i < n; i++) {           
            smallest = min(smallest, s[i]);
            largest = max(largest, s[i]);
            if (s[i] < s[i - 1]) 
                isSorted = 0;
        }

        if (isSorted) 
            return 0;
        if (n == 2) 
            return -1;
        if (s[0] == smallest || s[n - 1] == largest)
            return 1;        

        for (int i = 1; i < n - 1; i++)
            if (s[i] == smallest || s[i] == largest)
                return 2;

        return 3;
    }
};

int main() {
    Solution s;
    cout << s.minOperations("edbc");
    return 0;
}