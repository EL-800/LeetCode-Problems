#include <bits/stdc++.h>

using namespace std;

class Bank {
private:
    int n; 
    vector<long long> balance;

public:
    Bank(vector<long long>& balance) {
        n = balance.size();
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if (account1 < 0 || account1 >= n)
            return false;
        if (account2 < 0 || account2 >= n)
            return false;
        if (balance[account1] < money)
            return false;
        balance[account1] -= money;
        balance[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        account--;
        if (account < 0 || account >= n)
            return false;
        balance[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        account--;
        if (account < 0 || account >= n)
            return false;
        if (balance[account] < money)
            return false;
        balance[account] -= money;
        return true;
    }
};

int main() {
    return 0;
}