#include <iostream>

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == 0)
            {
                if (j + 2 >= nums.size())
                    return -1;
                ans++;
                nums[j] = 1;
                nums[j + 1] = 1 - nums[j + 1];
                nums[j + 2] = 1 - nums[j + 2];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 1, 1, 0, 0};
    cout << s.minOperations(nums) << endl;
    return 0;
}