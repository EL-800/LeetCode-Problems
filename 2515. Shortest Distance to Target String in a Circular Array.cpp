#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int currInd = (startIndex + i) % n;
            if (words[currInd] == target)  
                ans = min({ans, i, n - i});            
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    return 0;
}