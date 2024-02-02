#include <bits/stdc++.h>

using namespace std;

class Solution {
private:    
    int low, high;
    vector<int> ans;

    void SearchNums(int curr) {
        if (curr > high)
            return;
        if (curr >= low)
            ans.push_back(curr);
        int add = curr % 10 + 1;
        if (add > 9)
            return;
        SearchNums(curr * 10 + add);                   
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        this->low = low;
        this->high = high;
        ans.clear();
        for (int i = 1; i <= 9; i++)
            SearchNums(i);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    return 0;
}