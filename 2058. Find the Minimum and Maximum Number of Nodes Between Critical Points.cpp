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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head;
        stack<int> criticalsPoints;
        int prev, ind = 0;        
        prev = curr->val;
        curr = curr->next;
        while (curr->next) {
            if ((prev < curr->val && curr->next->val < curr->val) || (prev > curr->val && curr->next->val > curr->val)) 
                criticalsPoints.push(ind);
            prev = curr->val;
            curr = curr->next;                                                
            ind++;
        }
        if (criticalsPoints.size() < 2)
            return {-1, -1};
        vector<int> ans(2);
        ans[0] = INT_MAX;
        ans[1] = criticalsPoints.top();
        while (criticalsPoints.size() > 1) {
            int prev = criticalsPoints.top();
            criticalsPoints.pop();
            ans[0] = min(ans[0], prev - criticalsPoints.top());
        }
        ans[1] -= criticalsPoints.top();
        return ans;
    }
};

int main() {
    return 0;
}