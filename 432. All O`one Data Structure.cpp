#include <bits/stdc++.h>

using namespace std;

class AllOne {
private:
    unordered_map<string, int> keysPresent;
    set<pair<int, string>> keysCount;

public:    
    void inc(string key) {
        if (!keysPresent.count(key)) {
            keysPresent[key] = 1;
            keysCount.insert({1, key});
            return;
        }
        auto [k, v] = *keysPresent.find(key);        
        keysCount.erase({v, k});
        keysCount.insert({v + 1, k});
        keysPresent[k] = v + 1;
    }
    
    void dec(string key) {
        auto [k, v] = *keysPresent.find(key);        
        keysCount.erase({v, k});
        if (v > 1) {
            keysCount.insert({v - 1, key});                                    
            keysPresent[k] = v - 1;        
        }
        else 
            keysPresent.erase(k);
    }
    
    string getMaxKey() {
        if (!keysCount.size())
            return "";
        return keysCount.rbegin()->second;
    }
    
    string getMinKey() {
        if (!keysCount.size())
            return "";
        return keysCount.begin()->second;
    }
};

int main() {
    return 0;
}