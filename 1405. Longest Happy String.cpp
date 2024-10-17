#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> greatests;
        string ans;
        if (a)
            greatests.push({a, 'a'});
        if (b)
            greatests.push({b, 'b'});
        if (c)
            greatests.push({c, 'c'});
        while (!greatests.empty()) {
            auto [q, l] = greatests.top();
            greatests.pop();
            if (ans.size() > 2 && *ans.rbegin() == *next(ans.rbegin()) && *ans.rbegin() == l) {
                if (greatests.empty())
                    return ans;
                auto [sq, sl] = greatests.top();
                greatests.pop();
                ans += sl;
                if (sq > 1)
                    greatests.push({sq - 1, sl});
            }
            ans += l;
            if (q > 1)
                greatests.push({q - 1, l});
        }
        return ans;
    }
};

int main() {
    return 0;
}