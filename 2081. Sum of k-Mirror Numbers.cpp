#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int k;

    bool IsMirrorK(string &num) {
        long long iNum = stoll(num);
        string numBaseK;
        while (iNum) {
            numBaseK.push_back((iNum % k) + '0');
            iNum /= k;
        }
        
        int n = numBaseK.size();
        for (int i = 0; i < n / 2; i++) {
            if (numBaseK[i] != numBaseK[n - i - 1])
                return false;                
        }
        return true;
    }

    long long MirrorNum(string &num, int &n, int size, int ind = 0) {
        if (!n)
            return 0;        
        if (ind > size - ind - 1 && IsMirrorK(num)) { 
            n--;
            return stoll(num);            
        }        
        if (ind > size - ind - 1)
            return 0;    
        long long count = 0;
        for (int i = '0'; i <= '9'; i++) {
            if (!ind && i == '0')
                continue;            
            num[ind] = i;
            num[size - ind - 1] = i;
            count += MirrorNum(num, n, size, ind + 1);
        }        
        return count;
    }

public:
    long long kMirror(int k, int n) {
        this->k = k;        
        int digitSize = 1;
        long long ans = 0;
        while (n) {
            string num(digitSize, '0');
            ans += MirrorNum(num, n, digitSize);
            digitSize++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.kMirror(2, 6);
    return 0;
}