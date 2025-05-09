class Solution
{
public:
    const int mod = 1e9 + 7;
    vector<int> freq;
    vector<int> fact;
    vector<int> ifact;
    vector<vector<vector<int>>> dp;
    int n;
    int target;
    int binaryExpo(int i, int p)
    {
        long long result = 1;
        while (p > 0)
        {
            if (p % 2 == 1)
            {
                result = (result * i) % mod;
                p--;
            }
            i = (1LL * i * i) % mod;
            p /= 2;
        }
        return result;
    }
    int solve(int num, int oddsZ, int currSum)
    {
        if (num == 10)
        {
            if (oddsZ == n / 2 && currSum == target)
            {
                return (1LL * fact[oddsZ] * fact[n - oddsZ]) % mod;
            }
            else
                return 0;
        }
        if (currSum > target)
            return 0;
        if (dp[num][oddsZ][currSum] != -1)
            return dp[num][oddsZ][currSum];
        int ans = 0;
        for (int oddCount = 0; oddCount <= min(freq[num], n / 2 - oddsZ);
             oddCount++)
        {
            int evenCount = freq[num] - oddCount;
            ans = (ans + (((1LL * ifact[oddCount] * ifact[evenCount]) % mod) *
                          solve(num + 1, oddsZ + oddCount,
                                currSum + oddCount * num) %
                          mod)) %
                  mod;
        }
        return dp[num][oddsZ][currSum] = ans;
    }
    int countBalancedPermutations(string num)
    {
        n = num.size();
        freq.resize(10);
        fact.resize(n + 1, 1);
        ifact.resize(n + 1, 1);
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += num[i] - '0';
            freq[num[i] - '0']++;
        }
        if (totalSum % 2 == 1)
        {
            return 0;
        }
        target = totalSum / 2;
        dp.resize(10,
                  vector<vector<int>>(n / 2 + 1, vector<int>(target + 1, -1)));
        for (int i = 1; i < n + 1; i++)
        {
            fact[i] = (1LL * i * fact[i - 1]) % mod;
            ifact[i] = binaryExpo(fact[i], mod - 2) % mod;
        }

        return solve(0, 0, 0);
    }
};
