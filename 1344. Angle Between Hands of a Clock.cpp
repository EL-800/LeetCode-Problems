#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double dMinute = minutes, dHours = (hour % 12) * 5;
        dHours += dMinute * 5 / 60;        
        double minuteDegree = dMinute * 360 / 60;
        double hourDegree = dHours * 360 / 60;
        double diff = abs(hourDegree - minuteDegree);

        return min(360 - diff, diff);
    }
};

int main() {
    return 0;
}