#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const double epsilon = 1e-6;    

    bool Search(vector<double> &nums) {
        if (nums.size() == 1)
            return fabs(nums[0] - 24.0) < epsilon;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                                
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k == i || k == j)
                        continue;
                    next.push_back(nums[k]);
                }                                    

                double a = nums[i], b = nums[j];
                vector<double> operations({a + b, a - b, b - a, a * b});
                if (a > epsilon)
                    operations.push_back(b / a);
                if (b > epsilon)
                    operations.push_back(a / b);
                
                for (auto op : operations) {
                    next.push_back(op);
                    if (Search(next))
                        return true;
                    next.pop_back();
                }                
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int card : cards)
            nums.push_back((double)card);
        return Search(nums);
    }
};

int main() {
    return 0;
}