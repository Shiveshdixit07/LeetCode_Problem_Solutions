class Solution
{
public:
    int totalFruit(vector<int> &f)
    {
        unordered_map<int, int> mp;
        int cnt = 0;
        int i = 0, n = f.size();
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            mp[f[j]]++;
            if (mp[f[j]] == 1)
                cnt++;
            while (i < j && cnt > 2)
            {
                mp[f[i]]--;
                if (mp[f[i]] == 0)
                    cnt--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};