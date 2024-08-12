#include <bits/stdc++.h>

using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> greatests;

public:
    KthLargest(int k, vector<int>& nums) {
        k = this->k;
        for (int num : nums)                     
            add(num);
    }
    
    int add(int val) {
        greatests.push(val);
        if (greatests.size() > k)
            greatests.pop();
        return greatests.top();
    }
};

int main() {
    vector<int> c = {4, 5, 8, 2};
    KthLargest s(3, c);    
    return 0;
}