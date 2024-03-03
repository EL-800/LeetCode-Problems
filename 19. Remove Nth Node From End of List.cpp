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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *LR = head, *RL = head;
        while (n--)
            LR = LR->next;
        if (!LR)
            return head->next;
        while (LR->next) {
            LR = LR->next;
            RL = RL->next;
        }
        RL->next = RL->next->next;
        return head;
    }
};

int main(){
    return 0;
}