#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int dis = 0, balls = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            dis += balls;
            balls += boxes[i] - '0';
            ans[i] += dis;
        }
        dis = 0, balls = 0;
        for (int i = n - 1; i >= 0; i--) {
            dis += balls;
            balls += boxes[i] - '0';
            ans[i] += dis;          
        }
        return ans;
    }
};

int main() {
    return 0;
}