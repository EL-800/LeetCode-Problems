#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        vector<int> copyArr = arr;
        sort(copyArr.begin(), copyArr.end());
        copyArr[0] = 1;
        for (int i = 1; i < copyArr.size(); i++){
            if (copyArr[i] - copyArr[i - 1] > 1)
                copyArr[i] = copyArr[i - 1] + 1;            
        }
        return *copyArr.rbegin();
    }
};

int main(){
    return 0;
}