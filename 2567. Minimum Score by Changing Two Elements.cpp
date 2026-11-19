#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int k = 3;
        priority_queue<int, vector<int>, greater<>> greatests;
        priority_queue<int> lowests;
        
        for (int num : nums) {
            greatests.push(num);
            lowests.push(num);

            if (greatests.size() > k)
                greatests.pop();
            if (lowests.size() > k)
                lowests.pop();
        }
        
        int max3 = greatests.top(), min3 = lowests.top();
        greatests.pop(), lowests.pop();
        int max2 = greatests.top(), min2 = lowests.top();
        greatests.pop(), lowests.pop();
        int max1= greatests.top(), min1 = lowests.top();
        
        return min({max3 - min1, max2 - min2, max1 - min3});
    }
};

int main() {
    return 0;
}