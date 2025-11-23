#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        int totalSum = 0;
        priority_queue<int> mods1, mods2;
        for (int num : nums)
        {
            int mod = num % 3;
            totalSum += num;
            if (mod == 1)
            {
                mods1.push(num);
                if (mods1.size() > 2)
                    mods1.pop();
            }
            else if (mod == 2)
            {
                mods2.push(num);
                if (mods2.size() > 2)
                    mods2.pop();
            }
        }

        int totalMod = totalSum % 3;
        if (!totalMod)
            return totalSum;
        else if (totalMod == 1)
        {
            int opt1 = INT_MAX, opt2 = INT_MAX;
            if (!mods1.empty())
            {
                opt1 = mods1.top();
                mods1.pop();
                if (!mods1.empty())
                    opt1 = mods1.top();
            }
            if (mods2.size() == 2)
            {
                opt2 = mods2.top();
                mods2.pop();
                opt2 += mods2.top();
            }
            if (opt1 != INT_MAX || opt2 != INT_MAX)
                return totalSum - min(opt1, opt2);
            return 0;
        }
        int opt1 = INT_MAX, opt2 = INT_MAX;
        if (!mods2.empty())
        {
            opt1 = mods2.top();
            mods2.pop();
            if (!mods2.empty())
                opt1 = mods2.top();
        }
        if (mods1.size() == 2)
        {
            opt2 = mods1.top();
            mods1.pop();
            opt2 += mods1.top();
        }
        if (opt1 != INT_MAX || opt2 != INT_MAX)
            return totalSum - min(opt1, opt2);
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> c = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 152, 11, 142, 2, 10, 12, 3};
    cout << s.maxSumDivThree(c);
    return 0;
}