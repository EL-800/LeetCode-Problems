#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k >= arr.size())
            return *max_element(arr.begin(), arr.end());
        int first = arr[0];
        deque<int> list;
        for (int i = 1; i < arr.size(); i++)
            list.push_back(arr[i]);
        int streak = 0;
        while (streak < k){
            if (first < list.front()){
                streak = 1;
                swap(first, list.front());
            }
            else
                streak++;
            list.push_back(list.front());
            list.pop_front();
        }
        return first;
    }
};

int main(){
    return 0;
}