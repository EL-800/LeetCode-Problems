#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;
    vector<int> batteries;    

    bool Validate(long long target) {
        long long curr = 0;
        for (int i : batteries)
            curr += min(target, (long long)i);
        return curr >= target * n;
    }

    long long BS(long long left, long long right) {
        if (left == right)
            return left;
        long long mid = (left + right) / 2 + 1;
        if (Validate(mid))
            return BS(mid, right);
        return BS(left, mid - 1);
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        this->n = n;
        this->batteries = batteries;
        long long sum = 0;
        for (int i : batteries)
            sum += (long long)i;
        return BS(0, sum / (long long)n);
    }
};

int main() {
    return 0;
}