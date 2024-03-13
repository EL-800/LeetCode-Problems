#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int left = 0, right = n, allSum = n * (n + 1) / 2;
        while (left < right){
            int mid = (left + right) / 2 + 1;
            int leftSum = mid * (mid + 1) / 2, rightSum = allSum - leftSum + mid;
            if (leftSum <= rightSum)
                left = mid;
            else
                right = mid - 1;
        }
        int finalLeftSum = left * (left + 1) / 2, finalRightSum = allSum - finalLeftSum + left;
        return finalLeftSum == finalRightSum ? left : -1;
    }
};

int main(){
    return 0;
}