#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string RevserseInvert(string array) {
        for (int i = 0; i < array.size(); i++) {
            if (array[i] == '1')
                array[i] = '0';
            else
                array[i] = '1';
        }
        reverse(array.begin(), array.end());     
        return array;   
    }

    string MakeArray(int n) {
        if (n == 1)
            return "0";
            string prev = MakeArray(n - 1);
        return prev + "1" + RevserseInvert(prev);
    }

public:
    char findKthBit(int n, int k) {
        return MakeArray(n)[k - 1];
    }
};

int main() {
    return 0;
}