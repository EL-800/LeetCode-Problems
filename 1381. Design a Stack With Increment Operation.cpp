#include <bits/stdc++.h>

using namespace std;

class CustomStack {
private:
    int maxSize, currInd;
    int stack[1000];

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        currInd = -1;
    }
    
    void push(int x) {
        if (currInd + 1 >= maxSize)
            return;
        stack[++currInd] = x;
    }
    
    int pop() {
        if (currInd == -1)
            return currInd;        
        return stack[currInd--];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, currInd + 1); i++) 
            stack[i] += val;
    }
};

int main() {
    return 0;
}