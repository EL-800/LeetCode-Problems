#include <bits/stdc++.h>

using namespace std;

class MyCalendar {
private:
    vector<pair<int, int>> calendar;
public:
    bool book(int start, int end) {
        for (auto i : calendar) {
            if (max(i.first, start) < min(i.second, end))
                return false;
        }
        calendar.push_back({ start,end });
        return true;
    }
};

int main() {
    return 0;
}