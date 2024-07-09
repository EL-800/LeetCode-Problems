#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currTime = 0;
        double avg, n = (double)customers.size();
        for (auto customer : customers) {
            currTime = max(customer[0], currTime) + customer[1];
            avg += double(currTime - customer[0]) / n;
        }
        return avg;
    }
};

int main() {
    return 0;
}