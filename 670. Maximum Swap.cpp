#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string sNum = to_string(num);
        int n = sNum.size();
        for (int i = 0; i < n; i++) {
            int pos = 0;
            char maxD = '0';
            for (int j = n - 1; j > i; j--) {
                if (maxD < sNum[j]) {
                    maxD = sNum[j];
                    pos = j;
                }                
            }
            if (maxD > sNum[i]) {
                swap(sNum[i], sNum[pos]);
                return stoi(sNum);
            }
        }
        return num;
    }
};

int main() {
    return 0;
}