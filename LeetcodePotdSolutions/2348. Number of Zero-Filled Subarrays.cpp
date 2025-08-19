class Solution
{
public:
#define ll long long
    long long zeroFilledSubarray(vector<int> &nums)
    {
        ll ans = 0;
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                cnt++;
            }
            else
            {
                ans += 1LL * (cnt + 1) * cnt / 2;
                cnt = 0;
            }
        }
        ans += 1LL * (cnt + 1) * cnt / 2;
        return ans;
    }
};