class Solution
{
public:
#define ll long long
    long long countSubarrays(vector<int> &nums, long long k)
    {
        ll ans = 0;
        int i = 0;
        ll sum = 0;
        ll val = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            val = 1LL * sum * (j - i + 1);
            while (val >= k && i <= j)
            {
                sum -= nums[i];
                i++;
                val = 1LL * sum * (j - i + 1);
            }
            if (i <= j)
                ans += (j - i + 1);
        }
        return ans;
    }
};