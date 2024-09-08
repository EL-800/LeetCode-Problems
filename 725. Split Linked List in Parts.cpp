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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int n = 0;
        ListNode *currNode = head;
        while(currNode) {
            currNode = currNode->next;
            n++;
        }
        int partSize = n / k + 1, extras = n % k, currSize = 1, ansInd = 0;
        currNode = head;
        while(currNode) {
            if(!ans[ansInd])
                ans[ansInd] = currNode;
            if (!extras) {
                partSize--;
                extras = INT_MAX;
            }
            if (currSize == partSize) {
                auto next = currNode->next;
                currNode->next = nullptr;
                currNode = next;
                currSize = 1;
                ansInd++;
                extras--;
            }
            else {
                currNode = currNode->next;
                currSize++;
            }
        }
        return ans;        
    }
};

int main() {
    return 0;
}