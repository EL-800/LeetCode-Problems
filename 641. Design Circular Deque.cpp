#include <bits/stdc++.h>

using namespace std;

class MyCircularDeque {
private:
    int k, back, front, currSize = 0; 
    int dequeue[1000];

    void MoveFront() {
        front = (front + 1) % k;        
    }

public:
    MyCircularDeque(int k) {
        this->k = k;
        back = 0, front = 0;        
    }
    
    bool insertFront(int value) {
        if (currSize == k)
            return false;        
        if (currSize)
            front = (front + 1) % k; 
        dequeue[front] = value;                 
        currSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if (currSize == k)
            return false;        
        if (currSize)
            back = back - 1 < 0 ? k - 1 : back - 1;  
        dequeue[back] = value;                
        currSize++;
        return true;
    }
    
    bool deleteFront() {
        if (!currSize)
            return false;
        if (front != back)
            front = front - 1 < 0 ? k - 1 : front - 1;
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if (!currSize)
            return false;
        if (front != back)
            back = (back + 1) % k;
        currSize--;
        return true;
    }
    
    int getFront() {
        if (!currSize)
            return -1;
        return dequeue[front];
    }
    
    int getRear() {
        if (!currSize)
            return -1;
        return dequeue[back];
    }
    
    bool isEmpty() {
        return !currSize;
    }
    
    bool isFull() {
        return currSize == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
    return 0;
}