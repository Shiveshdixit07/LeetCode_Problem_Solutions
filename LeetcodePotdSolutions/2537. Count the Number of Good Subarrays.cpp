class Solution
{
public:
#define ll long long
    long long countGood(vector<int> &nums, int k)
    {
        ll n = nums.size();
        ll ans = 0;
        unordered_map<int, int> mp;
        ll count = 0;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            ll temp = mp[nums[j]]++;
            count += temp;
            while (count >= k && i < j)
            {
                ans += (n - j);
                ll t = mp[nums[i]];
                count -= (t - 1);
                mp[nums[i++]]--;
            }
        }
        return ans;
    }
};