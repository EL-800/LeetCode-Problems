#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int> heapGifts(gifts.begin(), gifts.end());
        while (k--) {
            int curr = heapGifts.top();
            heapGifts.pop();            
            curr = (int)sqrt(curr);
            heapGifts.push(curr);
        }
        while (!heapGifts.empty()) {
            ans += heapGifts.top();
            heapGifts.pop();
        }
        return ans;
    }
};

int main() {
    return 0;
}