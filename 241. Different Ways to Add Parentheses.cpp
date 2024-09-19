#include <bits/stdc++.h>

using namespace std;

class Solution {
private:    
    int Operation(int num1, int num2, char op) {
        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
        }
        return 0;
    }    

public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> curr;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int lNum : left) {
                    for (int rNum : right) 
                        curr.push_back(Operation(lNum, rNum, expression[i]));
                }
            }
        }
        if (curr.empty())
            curr.push_back(stoi(expression));
        return curr;        
    }
};

int main() {
    return 0;
}