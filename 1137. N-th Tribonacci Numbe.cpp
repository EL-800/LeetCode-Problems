#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (!n)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        vector<int> triSerie(n + 1);        
        triSerie[1] = 1;
        triSerie[2] = 1;
        for (int i = 3; i <= n; i++)
            triSerie[i] = triSerie[i - 1] + triSerie[i - 2] + triSerie[i - 3];
        return triSerie.back();
    }
};

int main(){    
    return 0;
}