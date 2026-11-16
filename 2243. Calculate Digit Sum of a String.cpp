#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {        
        string aux;        

        while (s.length() > k) {
            aux.clear();
            int n = s.length(), currSum = 0;
            for (int i = 0; i < n; i++) {
                if (!(i % k) && i) {
                    aux.append(to_string(currSum));
                    currSum = 0;
                }
                currSum += s[i] - '0';
            }
            aux.append(to_string(currSum));
            s = aux;
        }

        return s;
    }
};

int main() {
    return 0;
}