#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {        
        sort(reservedSeats.begin(), reservedSeats.end());
        reservedSeats.push_back({-1, -1});
        int m = reservedSeats.size(), checkedRows = 0;

        int currRow = reservedSeats[0][0], ans = 0;
        bitset<3> groups;
        groups.set();
        for (int i = 0; i < m; i++) {
            if (reservedSeats[i][0] != currRow) {
                if (groups[0] && groups[2])
                    ans += 2;
                else if (groups.any())
                    ans++;                   

                currRow = reservedSeats[i][0];
                groups.set();
                checkedRows++;                                      
            }

            if (reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 5) 
                groups.set(0, false);
            if (reservedSeats[i][1] >= 4 && reservedSeats[i][1] <= 7) 
                groups.set(1, false);
            if (reservedSeats[i][1] >= 6 && reservedSeats[i][1] <= 9) 
                groups.set(2, false);                          
        }

        return (n - checkedRows) * 2 + ans;
    }
};

int main() {
    return 0;
}