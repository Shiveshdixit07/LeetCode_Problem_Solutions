class Solution
{
public:
#define ll long long
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        ll ans = 0;
        int n = nums.size();
        int i = 0;
        ll cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % modulo == k)
                cnt = (cnt + 1) % modulo;
            int req = (cnt - k + modulo) % modulo;
            req >= 0 ? ans += mp[req] : 0;
            mp[cnt]++;
        }
        return ans;
    }
};