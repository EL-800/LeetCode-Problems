#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, r, k;
    vector<long long> sweepLine;    

    bool IsPossible(long long val) {  
        vector<long long> currSweep = sweepLine;      
        long long currSum = 0, addsAvi = k;
        for (int i = 0; i < n; i++) {
            currSum += currSweep[i];            
            long long diff = val - currSum;
            if (diff > 0 && addsAvi >= diff) {
                currSum += diff;
                int end = min(i + r * 2 + 1, n);
                currSweep[end] -= diff;
                addsAvi -= diff;
            }
            else if (diff > 0)
                return false;
        }
        cout << "\n";
        return true;        
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        n = stations.size();
        this->r = r;
        this->k = k;
        sweepLine.assign(n + 1, 0ll);
        for (int i = 0; i < n; i++) {
            int beg = max(i - r, 0), end = min(i + r + 1, n);
            sweepLine[beg] += (long long)stations[i];
            sweepLine[end] -= (long long)stations[i];
        }

        long long left = 0, right = LLONG_MAX;      
        while (left < right) {
            long long mid = (left + right) / 2 + 1;
            if (IsPossible(mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left;  
    }
};

int main() {
    return 0;
}