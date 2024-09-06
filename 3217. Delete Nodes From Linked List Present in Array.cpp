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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        unordered_set<int> bucket(nums.begin(), nums.end());
        while(curr) {
            if(bucket.count(curr->val)) {
                if (prev) 
                    prev->next = curr->next;
                else 
                    head = curr->next;
            }
            else
                prev = curr;            
            curr = curr->next;                
        }
        return head;
    }
};

int main() {
    return 0;
}