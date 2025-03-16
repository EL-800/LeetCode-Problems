#include <bits/stdc++.h>

using namespace std;

class Solution {
    private: 
            bool IsPossible(vector<int>& ranks, int cars, long long limitTime) {
                for (int rank : ranks) {
                    cars -=  floor(sqrt(limitTime / (long long)rank));
                    if (cars <= 0)
                        break;
                }
                return cars <= 0;
            }

    public:        
        long long repairCars(vector<int>& ranks, int cars) {
            long long left = 0, right = (long long)*max_element(ranks.begin(), ranks.end()) * (long long)cars * (long long)cars;
            while (left < right) {
                long long mid = (left + right) / 2;
                if (IsPossible(ranks, cars, mid))
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