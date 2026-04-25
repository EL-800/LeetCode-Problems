#include <bits/stdc++.h>

using namespace std;

class Solution {
private: 
    bool IsValid(vector<long long> &flattendCoords, int side, int k, int d) {
        int n = flattendCoords.size();

        for (int i = 0; i < n; i++) {
            int currInd = i, count = 1;

            while (count < k) {
                long long target = flattendCoords[currInd] + d;
                int j = lower_bound(flattendCoords.begin(), flattendCoords.end(), target) - flattendCoords.begin();

                if (j == n) 
                    break;

                currInd = j;
                count++;

                if (d + flattendCoords[currInd] > flattendCoords[i] + 4LL * side) {
                    count = 0;
                    break;
                }
            }

            if (count == k) 
                return true;
        }
        
        return false;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {        

        vector<long long> flattenCoords;
        for (auto &p : points) {
            long long x = p[0], y = p[1];
            if (y == 0) 
                flattenCoords.push_back(x);
            else if (x == side) 
                flattenCoords.push_back(side + y);                
            else if (y == side)                 
                flattenCoords.push_back(3ll * side - x);
            else 
                flattenCoords.push_back(4ll * side - y);
        }
        sort(flattenCoords.begin(), flattenCoords.end());
            
        long long left = 0, right = side;

        while (left < right) {
            long long mid = (left + right) / 2 + 1;

            if (IsValid(flattenCoords, side, k, mid)) 
                left = mid;            
            else 
                right = mid - 1;            
        }

        return (int)left;
    }
};

int main() {
    return 0;
}