#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seenValues;        
        for (int num : arr) {            
            if ((!(num % 2) && seenValues.count(num / 2)) || seenValues.count(num * 2))
                return true;
            seenValues.insert(num);
        }
        return false;
    }
};

int main() {
    return 0;
}