#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int, int>> countFreq(26, {0, -1});
        for (auto let : word) {
            int freq = countFreq[let - 'a'].first;
            countFreq[let - 'a'] = {freq + 1, let - 'a'};
        }
        sort(countFreq.rbegin(), countFreq.rend());
        vector<int> pushMap(26);
        for (int i = 0; i < 26; i++) {
            int l = countFreq[i].second;
            if (l == -1)
                continue;
            pushMap[l] = i / 8 + 1;            
        }
        int ans = 0;
        for (auto let : word) 
            ans += pushMap[let - 'a'];
        return ans;
    }
};

int main() {
    Solution s;
    s.minimumPushes("abcde");
    return 0;
}