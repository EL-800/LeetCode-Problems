#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int FindMaxSplit(string &s, unordered_set<string>& seen, int i = 0) {
        if (i == s.length())
            return 0;
        int maximum = 0;        
        string curr;        
        for (int j = i; j < s.length(); j++) {
            curr += s[j];
            if (seen.count(curr))
                continue;
            seen.insert(curr);
            maximum = max(maximum, FindMaxSplit(s, seen, j + 1) + 1);
            seen.erase(curr);
        }
        return maximum;
    }

public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return FindMaxSplit(s, seen);
    }
};

int main() {
    return 0;
}