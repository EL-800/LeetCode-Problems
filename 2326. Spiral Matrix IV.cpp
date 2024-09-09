#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int y = 0, x = 0, currMove = 0;
        ListNode* curr = head;
        ans[y][x] = curr->val;
        curr = curr->next;
        while(curr) {
            int nextY = y + moves[currMove].first, nextX = x + moves[currMove].second;
            if (nextY < 0 || nextY >= m || nextX < 0 || nextX >= n || ans[nextY][nextX] != -1) {
                currMove = (currMove + 1) % moves.size();
                continue;                
            }
            ans[nextY][nextX] = curr->val;
            curr = curr->next;
            y = nextY;
            x = nextX;                
        }
        return ans;
    }
};

int main() {
    return 0;
}