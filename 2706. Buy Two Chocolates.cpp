#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int lowest = INT_MAX, nextLowest;
        for (int price : prices){
            if (lowest > price){
                nextLowest = lowest;
                lowest = price;                
            }
            else if (nextLowest > price)
                nextLowest = price;
        }
        int ans = money - (lowest + nextLowest);
        return ans < 0 ? money : ans;
    }
};

int main(){
    return 0;
}