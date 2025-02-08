#include <bits/stdc++.h>

using namespace std;

class NumberContainers {
private:
    set<pair<int, int>> lowestInd;
    unordered_map<int, int> indVal;

public:
    NumberContainers() {
            
    }
        
    void change(int index, int number) {
        if (indVal.count(index)) 
            lowestInd.erase({indVal[index], index});        
        indVal[index] = number;
        lowestInd.insert({number, index});
    }
        
    int find(int number) {        
        auto val = *lowestInd.lower_bound({number, 1});
        return val.first == number ? val.second : -1;
    }
};

int main() {
    return 0;
}