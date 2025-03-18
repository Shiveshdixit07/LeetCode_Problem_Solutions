#include <iostream>

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int longestNiceSubarray(vector<int> &nums)
{
    int i = 0;

    int ans = 0;
    int curr = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        while (i < j && (curr & nums[j]) != 0)
        {
            curr ^= nums[i++]; // unsetting the bits for the nums[i]
        }
        curr |= nums[j]; // setting the bits for the nums[j]
        ans = max(ans, (j - i + 1));
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 8, 48, 10}; // Sample Input
    cout << longestNiceSubarray(nums) << endl;
    return 0;
}