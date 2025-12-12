#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        /*eventTimes save as key the time of the event and event type
        the second value of the key will say the operation type as follows:
        0. Goes online
        1. Goes offline
        2. Message
        The vector values will store the affected users by the operation. Will save the id with his number and HERE and ALL with -1 and -2 respectevly
        */
        multimap<pair<int, int>, vector<int>>  eventsTimes;        

        for (auto event : events) {
            string type = event[0];
            int time = stoi(event[1]);            

            if (type == "MESSAGE") {  
                vector<int> evenenData;                              
                stringstream ids(event[2]);
                string id;
                while (ids >> id) {
                    if (id == "HERE")
                        evenenData.push_back(-1);
                    else if (id == "ALL")   
                        evenenData.push_back(-2);  
                    else                                
                        evenenData.push_back(stoi(id.substr(2)));                                
                }
                eventsTimes.insert({{time, 2}, evenenData});
            }

            else {
                vector<int> evenenDataOnline, evenenDataOffline;              
                int id = stoi(event[2]);
                eventsTimes.insert({{time, 1}, {id}});             
                eventsTimes.insert({{time + 60, 0}, {id}});
            }            
        }

        vector<int> ans(n);
        unordered_set<int> online;
        for (int i = 0; i < n; i++)
            online.insert(i);

        for (auto [key, data] : eventsTimes) {
            if (key.second == 0) 
                online.insert(data[0]);            
            else if (key.second == 1) 
                online.erase(data[0]);
            else {
                for (int id : data) {
                    if (id == -1) {
                        for (int curr : online)
                            ans[curr]++;
                    }
                    else if (id == -2) {
                        for (int i = 0; i < n; i++)
                            ans[i]++;
                    }
                    else 
                        ans[id]++;                                            
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<string>> c = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","71","HERE"}};
    Solution s;
    s.countMentions(2, c);
    return 0;
}