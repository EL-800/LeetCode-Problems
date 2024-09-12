#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> bucket(allowed.begin(), allowed.end());
        int ans = 0;
        for(string word : words) {
            for(char let : word) {
                if(!bucket.count(let)) {
                    ans--;
                    break;
                }
            }
            ans++;                
        }
        return ans;
    }
};

int main() {
    return 0;
}