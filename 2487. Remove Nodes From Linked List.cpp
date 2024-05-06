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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> currNodes;
        ListNode* curr = head;
        while (!curr){
            while (!currNodes.empty() && curr->val > currNodes.top()->val) {
                delete(currNodes.top());
                currNodes.pop();
            }                
            if (currNodes.empty())
                head = curr;
            else
                currNodes.top()->next = curr;
            currNodes.push(curr);
            curr = curr->next;
        }
        return head;
    }
};

int main(){
    return 0;
}