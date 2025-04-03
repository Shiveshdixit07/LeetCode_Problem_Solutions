class Solution
{
public:
#define ll long long
    long long maximumTripletValue(vector<int> &nums)
    {
        ll ans = 0;
        ll maxA = nums[0];
        ll maxAminusB = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            maxAminusB = max(maxAminusB, maxA - nums[i]);
            ans = max(ans, 1LL * maxAminusB * nums[i + 1]);
            maxA = max(maxA, 1LL * nums[i]);
        }
        return ans;
    }
};