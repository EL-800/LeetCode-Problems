#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int currLvl = 0;
        for (string log : logs) {
            if (log == "../") 
                currLvl = max(0, currLvl - 1);
            else if (log == "./")
                continue;
            else
                currLvl++;            
        }
        return currLvl;
    }
};

int main() {
    return 0;
}