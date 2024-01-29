#include <bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    stack<int> s;

public:    
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }
        int aux = s.top();
        s.pop();
        push(x);
        s.push(aux);
    }

    int pop() {
        int aux = s.top();
        s.pop();
        return aux;
    }

    int peek() {
        return s.top();
    }

    bool empty() {
        return s.empty();
    }
};

int main(){
    return 0;
}