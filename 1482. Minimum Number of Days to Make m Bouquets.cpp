#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool CheckDayX(vector<int>& bloomDay, int m, int k, int x){
        int bouquetsCount = 0, currBouquetSize = 0;
        for (int day : bloomDay){
            if (x >= day)
                currBouquetSize++;
            else
                currBouquetSize = 0;
            if (currBouquetSize == k){
                bouquetsCount++;
                currBouquetSize = 0;
            }
        }
        return bouquetsCount >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxE = *max_element(bloomDay.begin(), bloomDay.end()), left = 0, right = maxE + 1;
        while (left < right){
            int mid = (left + right) / 2;
            if (CheckDayX(bloomDay, m, k, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left > maxE ? -1 : left;
    }
};

int main(){
    return 0;
}