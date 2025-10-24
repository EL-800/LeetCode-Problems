#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool IsBalanced(int i) {
        vector<int> count(10);
        while (i) {
            int digit = i % 10;
            count[digit]++;
            i /= 10;
        }

        for (int i = 0; i < 10; i++) {
            if (!count[i])
                continue;
            if (count[i] != i)
                return false;
        }
        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        int i;
        for (i = n + 1; !IsBalanced(i); i++);
        return i;
    }
};

int main() {

}