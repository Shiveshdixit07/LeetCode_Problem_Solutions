class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &p, vector<int> &t)
    {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        int ans = 0;
        int j = 0;
        for (int i = 0; i < p.size() && j < t.size(); i++)
        {
            while (j < t.size() && t[j] < p[i])
                j++;
            if (j < t.size())
            {
                ans++, j++;
            }
        }
        return ans;
    }
};