#include <bits/stdc++.h>

using namespace std;

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> seatsAvilable;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
            seatsAvilable.push(i);
    }
    
    int reserve() {
        int seat = seatsAvilable.top();
        seatsAvilable.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        seatsAvilable.push(seatNumber);
    }
};

int main(){
    return 0;
}