class Solution
{
public:
    int candy(vector<int> &r)
    {
        map<int, vector<int>> mp;
        int n = r.size();
        for (int i = 0; i < n; i++)
        {
            mp[r[i]].push_back(i);
        }
        vector<int> temp(n, 1);
        int ans = 0;
        for (auto it : mp)
        {
            for (auto idx : it.second)
            {
                if (idx - 1 >= 0 && r[idx] > r[idx - 1] &&
                    temp[idx] <= temp[idx - 1])
                {
                    temp[idx] = temp[idx - 1] + 1;
                }
                if (idx + 1 < n && r[idx] > r[idx + 1] &&
                    temp[idx] <= temp[idx + 1])
                {
                    temp[idx] = temp[idx + 1] + 1;
                }
                ans += temp[idx];
            }
        }
        return ans;
    }
};