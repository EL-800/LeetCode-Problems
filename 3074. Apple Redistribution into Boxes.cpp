#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());
        int currCap = 0;
        for (int i = 0; i < capacity.size(); i++) {
            currCap += capacity[i];
            if (currCap >= totalApples)
                return i + 1;                
        }
        return 800;
    }
};

int main() {
    return 0;
}