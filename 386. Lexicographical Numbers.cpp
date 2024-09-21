#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n, int k = 1) {
        if (k > n)
            return vector<int>();
        vector<int> curr;
        for (int i = k; i < k * 10 && i < k + 10 && i <= n; i++) {
            curr.push_back(i);
            vector<int> next = lexicalOrder(n, i * 10);
            curr.insert(curr.end(), next.begin(), next.end());
        }
        return curr;
    }
};

int main() {
    return 0;
}