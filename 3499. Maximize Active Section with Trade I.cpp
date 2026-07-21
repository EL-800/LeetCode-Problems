#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int count = 0, totalOnes = 0;
        vector<int> segments;
        for (int i = 0; i < s.length(); i++) {                            
            if (s[i] != s[i + 1]) {
                segments.push_back(count + 1);
                count = 0;
            }
            else
                count++;
            totalOnes += s[i] == '1';
        }

        int delta = 0;
        bool zeroOrOne = s[0] - '0';
        for (int i = 0; i < segments.size() - 1; i++) {
            if (zeroOrOne && i)
                delta =  max(delta, segments[i - 1] + segments[i + 1]);
            zeroOrOne = !zeroOrOne;                                                 
        }
        
        return totalOnes + delta;
    }
};

int main() {
    return 0;
}