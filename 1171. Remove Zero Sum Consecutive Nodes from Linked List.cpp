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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *begin = head, *prev = NULL;
        while (begin){
            int currSum = 0;
            ListNode *end = begin;
            bool broke = false;
            while(end){
                currSum += end->val;
                if (!currSum) {
                    if (!prev)                        
                        head = begin = end->next;                                                                                    
                    else 
                        begin = prev->next = end->next;
                    broke = true;
                    break;
                }
                end = end->next;
            }
            if (!broke) {
                prev = begin;
                begin = begin->next;                
            }
        }
        return head;
    }
};

int main(){
    ListNode *list = new ListNode(0, new ListNode(0));
    Solution s;
    s.removeZeroSumSublists(list);
    return 0;
}