#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {   
        int n = max(fruits.back()[0], startPos + k) + 1;
        vector<int> fruitsArr(n);
        for (auto &fruit : fruits)
            fruitsArr[fruit[0]] = fruit[1];        
        for (int i = 1; i < n; i++) 
            fruitsArr[i] += fruitsArr[i - 1];

        int ans = 0;        
        for (int i = startPos; i < n && i <= startPos + k; i++) {
            int leftInd = i - k + (i - startPos);
            if (leftInd < 0)
                leftInd = 0;
            else if (leftInd > startPos)
                leftInd = startPos;
            int leftSum = fruitsArr[startPos] - (leftInd ? fruitsArr[leftInd - 1] : 0);
            int rightSum = fruitsArr[i] - fruitsArr[startPos];
            ans = max(ans, leftSum + rightSum);
        }

        for (int i = startPos; i >= 0 && i >= startPos - k; i--) {
            int rightInd = i + k - (startPos - i);
            if (rightInd >= n)
                rightInd = n - 1;
            else if (rightInd < startPos)
                rightInd = startPos;
            int rightSum = fruitsArr[rightInd] - (startPos ? fruitsArr[startPos - 1] : 0);
            int leftSum = (startPos ? fruitsArr[startPos - 1] : 0) - (i ? fruitsArr[i - 1] : 0);            
            ans = max(ans, leftSum + rightSum);
        }
        return ans;
    }
};

int main() {
    return 0;
}