#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        int left = 0, right = skill.size() - 1, sum = -1;
        sort(skill.begin(), skill.end());
        while (left < right) {
            if (sum == -1)
                sum = skill[left] + skill[right];
            if (sum != skill[left] + skill[right])
                return -1; 
            ans += (long long)skill[left] * (long long)skill[right];
            left++;
            right--;
        }
        return ans;
    }
};

int main() {
    return 0;
}