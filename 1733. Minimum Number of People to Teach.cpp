#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> pendingTeaches;

        for (auto &friendship : friendships) {
            bool shareLanguage = false;
            for (int language1 : languages[friendship[0] - 1]) {
                for (int language2 : languages[friendship[1] - 1]) {
                    if (language1 == language2) {
                        shareLanguage = true;
                        break;
                    }
                }
            }
            if (!shareLanguage) {
                pendingTeaches.insert(friendship[0] - 1);
                pendingTeaches.insert(friendship[1] - 1);
            }
        }

        int ans = INT_MAX;
        for (int teachingLanguage = 1; teachingLanguage <= n; teachingLanguage++) {    
            int teachedFriends = 0;        
            for (int pendingFriend : pendingTeaches) {
                bool knownLanguage = false;
                for (int language : languages[pendingFriend]) {
                    if (teachingLanguage == language) { 
                        knownLanguage = true;
                        break;;
                    }
                }
                if (!knownLanguage)
                    teachedFriends++; 
            }
            ans = min(ans, teachedFriends);
        }

        return ans;
    }
};

int main() {
    return 0;
}