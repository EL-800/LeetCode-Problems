#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = 0, bottlesDrunk = 0;
        while (numBottles + emptyBottles >= numExchange) {           
            bottlesDrunk += numBottles;
            emptyBottles += numBottles - numExchange;
            numBottles = numExchange;    
            numExchange++;        
        }
        return bottlesDrunk + numBottles;
    }
};

int main() {
    return 0;
}