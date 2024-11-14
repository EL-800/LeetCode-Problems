#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool IsPossible(int n, vector<int>& quantities, int storeQ) {
        int count = 0;
        for (int q : quantities) 
            count += ceil(float(q) / storeQ);        
        return count <= n;
    }

    int BS(int n, vector<int>& quantities) {
        int left = 0, right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = (left + right) / 2;
            if (IsPossible(n, quantities, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        return BS(n, quantities);
    }
};

int main() {
    return 0;
}