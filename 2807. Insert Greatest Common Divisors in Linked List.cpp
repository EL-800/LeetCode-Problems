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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head;
        while (curr->next) {
            ListNode *gcdNode = new ListNode(__gcd(curr->val, curr->next->val), curr->next);
            curr->next = gcdNode;
            curr = curr->next->next;
        }
        return head;
    }
};

int main() {
    return 0;    
}