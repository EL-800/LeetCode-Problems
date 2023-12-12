#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int k = 2;
        priority_queue<int, vector<int>, greater<int>> largests;
        for (int num : nums){            
            largests.push(num);
            if (largests.size() > k)
                largests.pop();
        }
        int num1 = largests.top();
        largests.pop();
        int num2 = largests.top();        
        return (num1 - 1) * (num2 - 1); 
    }
};

int main (){
    return 0;
}