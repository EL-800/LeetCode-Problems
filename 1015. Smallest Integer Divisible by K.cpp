#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int curr = 1, size = 1;  

        if (k == 1)
            return 1;
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        while (curr) {            
            curr = ((curr * 10) + 1) % k;
            size++;
        }
        
        return size;
    }
};

int main() {
    return 0;
}