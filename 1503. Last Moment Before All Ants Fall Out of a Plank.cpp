#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeftDis = 0, maxRightDis = 0;
        if (!left.empty())
            maxLeftDis = *max_element(left.begin(), left.end());        
        if (!right.empty())
            maxRightDis = n - *min_element(right.begin(), right.end());
        return max(maxLeftDis, maxRightDis);
    }
};

int main(){
    return 0;
}