#include <bits/stdc++.h>

using namespace std;

class TaskManager {
private:
    unordered_map<int, set<vector<int>>::iterator> tasksIterators;
    set<vector<int>> tasksSet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &task : tasks) 
            add(task[0], task[1], task[2]);                              
    } 
    
    void add(int userId, int taskId, int priority) {
        tasksIterators[taskId] = tasksSet.insert({priority, taskId, userId}).first;                
    }
    
    void edit(int taskId, int newPriority) {
        int userId = tasksIterators[taskId]->at(2);
        rmv(taskId);
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        tasksSet.erase(tasksIterators[taskId]);
        tasksIterators.erase(taskId);
    }
    
    int execTop() {
        if (tasksSet.empty())
            return -1;
        int taskId = tasksSet.rbegin()->at(1), userId = tasksSet.rbegin()->at(2);
        rmv(taskId);
        return userId;
    }
};


int main() {
    return 0;
}