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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *insertionBegin = list1, *insertionEnd = list1, *list2End = list2;
        while (list2End->next)
            list2End = list2End->next; 
        a--;       
        while (a--)
            insertionBegin = insertionBegin->next;        
        b++;
        while (b--)
            insertionEnd = insertionEnd->next;
        insertionBegin->next = list2;
        list2End->next = insertionEnd;
        return list1;
    }
};

int main(){
    return 0;
}