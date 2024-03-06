#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode *slow, *fast;
        slow = fast = head;
        do{            
            if (!fast->next)
                return false;
            fast = fast->next->next;
            slow = slow->next;            
        }while(fast != slow);
        return true;
    }
};

int main(){
    return 0;
}