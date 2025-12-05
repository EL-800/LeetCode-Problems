#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size(), left = 0, right = n - 1;
        while (left < n && directions[left] == 'L')
            left++;
        while (right >= 0 && directions[right] == 'R')
            right--;;
        cout << left << " " << right << "\n";
        return count_if(directions.begin() + left, directions.begin() + right + 1, [](char val) { return val == 'L' || val == 'R';});
    }
};

int main() {
    return 0;
}