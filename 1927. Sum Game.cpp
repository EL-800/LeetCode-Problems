#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), leftSum = 0, rightSum = 0, lQuestionsCount = 0, rQuestionsCount = 0;

        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?') 
                lQuestionsCount++;
            else 
                leftSum += num[i] - '0';
        }

        for(int i = n / 2; i < n; i++) {
            if(num[i] == '?') 
                rQuestionsCount++;
            else 
                rightSum += num[i] - '0';
        }

        return 2 * (leftSum - rightSum) != (rQuestionsCount - lQuestionsCount) * 9;
    }
};

int main() {
    return 0;
}