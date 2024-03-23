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
    void reorderList(ListNode* head) {
        stack<ListNode*> ends;
        ListNode* left = head;
        while (left->next) {
            ends.push(left);        
            left = left->next;
        }
        left = head;        
        while (left && left->next){
            ListNode *right = ends.top(), *next = left->next;      
            if (left == right)
                break;      
            ends.pop();
            right->next->next = left->next;
            left->next = right->next;
            left = next;            
            right->next = nullptr;
        }        
    }
};

int main(){
    Solution s;
    s.reorderList(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4)))));
    return 0;
}