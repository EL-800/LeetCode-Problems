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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *modifiedListHead, *modifiedListInd, *prev;
        modifiedListHead = new ListNode();
        modifiedListInd = modifiedListHead;
        int currSum = 0;
        head = head->next;
        while (head) {
            if (!head->val) {
                modifiedListInd->val = currSum;
                modifiedListInd->next = new ListNode();
                prev = modifiedListInd;
                modifiedListInd = modifiedListInd->next;
                currSum = 0;
            }
            else
                currSum += head->val;
            head = head->next;
        }
        prev->next = NULL;
        delete(modifiedListInd);
        return modifiedListHead;
    }
};

int main() {
    return 0;
}