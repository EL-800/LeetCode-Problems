#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_set<string> found;

    void SearchAll(string &curr, int a, int b) {
        if (found.count(curr))
            return;
        found.insert(curr);

        string left = curr;
        rotate(left.begin(), left.begin() + b, left.end());
        SearchAll(left, a, b);

        string right = curr;
        for (int i = 1; i < right.size(); i += 2) {            
            int c = right[i] - '0';
            c = (c + a) % 10;
            right[i] = c + '0';
        }
        SearchAll(right, a, b);                
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        SearchAll(s, a, b);
        return *min_element(found.begin(), found.end());
    }
};

int main() {
    return 0;
}