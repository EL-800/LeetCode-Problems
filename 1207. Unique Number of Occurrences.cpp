#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> numbers;
        unordered_set<int> ocurrences;
        for (int i : arr)
            numbers[i]++;
        for (auto i : numbers) {
            if (ocurrences.find(i.second) != ocurrences.end())
                return false;
            ocurrences.insert(i.second);
        }
        return true;
    }
};

int main(){
    return 0;
}