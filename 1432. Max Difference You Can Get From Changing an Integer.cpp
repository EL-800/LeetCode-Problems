#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {        
        string sNum = to_string(num), biggest = sNum, lowest = sNum;
        for (int i = 0; i < sNum.length(); i++) {            
            if (sNum[i] != '9') {
                replace(biggest.begin(), biggest.end(), sNum[i], '9');
                break;
            }
        }
        if (sNum[0] != '1') 
            replace(lowest.begin(), lowest.end(), sNum[0], '1');                               
        else {
            for (int i = 0; i < sNum.length(); i++) {
                if (sNum[i] != '0' && sNum[i] != '1') {
                    replace(lowest.begin(), lowest.end(), sNum[i], '0');
                    break;
                }
            }
        }        
        return stoi(biggest) - stoi(lowest);
    }
};

int main() {
    return 0;
}