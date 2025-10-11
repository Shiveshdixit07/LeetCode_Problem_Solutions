class Solution
{
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    long long dp[100001];
    long long solve(int idx)
    {
        if (idx >= arr.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int newIdx =
            upper_bound(arr.begin(), arr.end(), arr[idx] + 2) - arr.begin();
        long long a, b;
        a = solve(idx + 1);
        b = 1LL * arr[idx] * mp[arr[idx]] + solve(newIdx);
        return dp[idx] = max(a, b);
    }
    long long maximumTotalDamage(vector<int> &power)
    {
        sort(power.begin(), power.end());

        for (int i = 0; i < power.size(); i++)
        {
            if (arr.empty() || arr.back() != power[i])
                arr.push_back(power[i]);
            mp[power[i]]++;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0);
    }
};