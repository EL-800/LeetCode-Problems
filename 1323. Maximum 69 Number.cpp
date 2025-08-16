#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        string snum = to_string(num);        
        for (int i = 0; i < snum.size(); i++) {
            if (snum[i] != '9') {
                snum[i] = '9';
                break;
            }
        }
        num = atoi(snum.c_str());
        return num;
    }
};

int main() {
    return 0;
}