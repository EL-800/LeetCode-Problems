#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<pair<unsigned long long, int>>> bookedRooms;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        vector<int> usedRooms(n);
        for (int i = 0; i < n; i++)
            freeRooms.push(i);        
        sort(meetings.begin(), meetings.end());
        for (vector<int> meeting : meetings){
            while (!bookedRooms.empty() && meeting[0] >= bookedRooms.top().first){
                freeRooms.push(bookedRooms.top().second);
                bookedRooms.pop();
            }
            if (!freeRooms.empty()){
                int room = freeRooms.top();
                freeRooms.pop();
                usedRooms[room]++;
                bookedRooms.push({(unsigned long long)meeting[1], room});
            }
            else{
                auto room = bookedRooms.top();      
                bookedRooms.pop();          
                usedRooms[room.second]++;
                bookedRooms.push({(unsigned long long)(room.first + (meeting[1] - meeting[0])), room.second});
            }
        }
        for (int i : usedRooms)
            cout << i << " ";
        return max_element(usedRooms.begin(), usedRooms.end()) - usedRooms.begin();
    }
};

int main(){
    vector<vector<int>> c = {{1,20},{2,10},{3,5},{4,9},{6,8}};
    Solution s;
    s.mostBooked(3, c);
    return 0;
}