#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size(), ans = 0;
            unordered_set<int> presents(arr.begin(), arr.end());
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int a = arr[i], b = arr[j], counter = 0;
                    while (presents.count(a + b)) {
                        int aux = b;
                        b = a + b;
                        a = aux;
                        counter++;
                    }
                    ans = max(ans, counter);
                }
            }
            return ans ? ans + 2 : 0;
        }
    };

int main() {
    return 0;
}