#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int indSandiwch = 0;
        queue<int> studentsQ;
        for (int i : students)
            studentsQ.push(i);
        int currNumStudents = 0;
        do{            
            currNumStudents = studentsQ.size();
            int ind = 0;
            while(ind++ < currNumStudents && indSandiwch < sandwiches.size()){
                if (sandwiches[indSandiwch] == studentsQ.front()){
                    studentsQ.pop();
                    indSandiwch++;
                }
                else{
                    studentsQ.push(studentsQ.front());
                    studentsQ.pop();                
                }
            }            
        }while(currNumStudents != studentsQ.size());
        return studentsQ.size();        
    }
};

int main(){
    return 0;
}