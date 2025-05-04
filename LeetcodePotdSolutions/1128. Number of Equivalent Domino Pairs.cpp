class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &d)
    {
        map<pair<int, int>, int> mp;
        for (auto &x : d)
        {
            if (x[0] > x[1])
            {
                mp[{x[0], x[1]}]++;
            }
            else
            {
                mp[{x[1], x[0]}]++;
            }
        }
        int ans = 0;
        for (auto &it : mp)
        {
            int val = it.second;
            ans += (val * (val - 1)) / 2;
        }
        return ans;
    }
};