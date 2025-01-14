#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), currOcurrences = 0;
        unordered_set<int> countA, countB;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            countA.insert(A[i]);
            countB.insert(B[i]);
            if (countA.count(B[i]))
                currOcurrences++;
            if (A[i] != B[i] && countB.count(A[i]))
                currOcurrences++;
            ans[i] = currOcurrences;
        }
        return ans;
    }
};

int main() {
    return 0;
}