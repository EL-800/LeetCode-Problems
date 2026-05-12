#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isValid(vector<vector<int>>& tasks, int val) {
        for (auto &task : tasks) {
            if (task[1] > val)
                return false;
            val -= task[0];
        }

        return true;
    }

public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.rbegin(), tasks.rend(), [](const vector<int> &a, const vector<int>& b) {
            return a[1] - a[0] < b[1] - b[0]; 
        });
        
        int left = 0, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(tasks, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main() {
    return 0;
}