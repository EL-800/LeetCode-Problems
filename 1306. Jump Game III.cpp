#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n;

    bool DFS(vector<int>& arr, int curr) {
        if (curr < 0 || curr >= n)
            return false;
        if (!arr[curr])        
            return true;
        if (arr[curr] == -1)
            return false;

        int jump = arr[curr];
        arr[curr] = -1;         
        if (DFS(arr, curr + jump) || DFS(arr, curr - jump))
            return true;

        return false;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return DFS(arr, start);
    }
};

int main() {
    return 0;
}