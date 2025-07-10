#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {   
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);     
        int n = startTime.size();
        map<int, int> emptySpaces;        
        for (int i = 0; i < n; i++) {
            int space = startTime[i] - ((i - 1 >= 0) ? endTime[i - 1] : 0);
            emptySpaces[space]++;
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int left = startTime[i] - ((i - 1 >= 0) ? endTime[i - 1] : 0);
            int right = startTime[i + 1] - endTime[i];
            emptySpaces[left]--;
            if (!emptySpaces[left])
                emptySpaces.erase(left);
            emptySpaces[right]--;
            if (!emptySpaces[right])
                emptySpaces.erase(right);
            if (emptySpaces.rbegin()->first >= endTime[i] - startTime[i])  
                ans = max(ans, left + right + endTime[i] - startTime[i]);   
            else
                ans = max(ans, left + right);   
            emptySpaces[left]++;
            emptySpaces[right]++;         
        }
        return ans;        
    }
};

int main() {
    return 0;
}