#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diffs = 0;
        unordered_map<char, int> count1, count2;
        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i]]++;
            count2[s2[i]]++;
            if (s1[i] != s2[i])
                diffs++;
        }
        return  count1 == count2 && diffs <= 2;
    }
};

int main() {
    return 0;
}