#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        int n, m, strength;

        int IsPossible(vector<int>& tasks, vector<int>& workers, int pills, int k) {
            vector<int> tasksK;
            vector<int> workersK;
            for (int i = 0; i < k; i++) {
                tasksK.push_back(tasks[i]);            
                workersK.push_back(workers[m - k + i]);
            }
            for (int i = k - 1; i >= 0 && pills > 0; i--) {
                if (tasksK[i] > workersK[i]) {
                    tasksK[i] -= strength;
                    pills--;
                }
            }
            sort(tasksK.begin(), tasksK.end());
            for (int i = 0; i < k; i++) {
                if (tasksK[i] > workersK[i])
                    return false;                    
            }
            return true;
        }

    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {            
            n = tasks.size();
            m = workers.size();
            this->strength = strength;
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
            int left = 0, right = min(n, m);
            while (left < right) {
                int mid = (left + right) / 2 + 1;
                if (IsPossible(tasks, workers, pills, mid))
                    left = mid;
                else
                    right = mid - 1;
            }
            return left;
        }
    };

int main() {
    return 0;
}