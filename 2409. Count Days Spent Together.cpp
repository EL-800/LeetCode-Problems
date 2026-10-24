#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int GetDay(string date) {
        vector<int> monthDays = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int month = (date[0] - '0') * 10 + (date[1] - '0'), day = (date[3] - '0') * 10 + (date[4] - '0');
        return monthDays[month - 1] + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveAliceDay = GetDay(arriveAlice), leaveAliceDay = GetDay(leaveAlice),
            arriveBobDay = GetDay(arriveBob), leaveBobDay = GetDay(leaveBob);        
        int left = max(arriveAliceDay, arriveBobDay), right = min(leaveBobDay, leaveAliceDay);
        return max(right - left + 1, 0);
    }
};

int main() {
    return 0;
}