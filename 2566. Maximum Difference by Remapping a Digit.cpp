#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline string ReplaceString(string &sNum, char c) {
        string obj = sNum;
        for (int i = 0; i < sNum.length(); i++) {
            if (sNum[i] != c) {
                replace(obj.begin(), obj.end(), sNum[i], c);
                break;
            }
        }
        return obj;
    }

public:
    int minMaxDifference(int num) {
        string sNum = to_string(num);
        string biggest = ReplaceString(sNum, '9');
        string lowest = ReplaceString(sNum, '0');
        return stoi(biggest) - stoi(lowest);
    }
};

int main() {

}