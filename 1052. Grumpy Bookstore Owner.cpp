#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), currTotal = 0;
        for (int i = 0; i < n; i++){
            if (!grumpy[i])
                currTotal += customers[i];
        }
        int left = 0, right = 0;
        while (right < minutes - 1){
            if (grumpy[right])
                currTotal += customers[right];
            right++;
        }       
        int maxTotal = 0; 
        while (right < n) {
            if (grumpy[right])
                currTotal += customers[right];                
            maxTotal = max(maxTotal, currTotal);
            if (grumpy[left])
                currTotal -= customers[left];
            left++;                        
            right++;
        }
        return maxTotal;
    }
};

int main(){
    return 0;
}