#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), beg = 0, end = 0, ans = 0;
        unordered_map<int, int> basckets;
        while (end < n) {
            if (basckets.size() <= 2) 
                basckets[fruits[end++]]++;                            
            else {
                basckets[fruits[beg]]--;
                if (!basckets[fruits[beg]])
                    basckets.erase(fruits[beg]);
                beg++;
            }
            if (basckets.size() <= 2) {
                int curr = 0;
                for (auto i : basckets)
                    curr += i.second;
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}