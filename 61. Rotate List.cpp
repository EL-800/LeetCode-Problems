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
private:
    ListNode* head;

    int GetListSize(ListNode *curr) {
        if (!curr)
            return 0;
        return GetListSize(curr->next) + 1;
    }

    void RotateList(ListNode *curr, int lastVal) {
        if (!curr) {
            head->val = lastVal;
            return;
        }          
        int aux = curr->val;
        curr->val = lastVal;        
        RotateList(curr->next, aux);
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;

        this->head = head;
        int n = GetListSize(head); 
        k = k % n;
        while (k--)
            RotateList(head->next, head->val);
        return head;
    }
};

int main() {
    return 0;
}