class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int n = tops.size();
        int ans = INT_MAX;
        for (int val = 1; val <= 6; val++)
        {
            bool f = 1;
            int c1 = 0, c2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (tops[i] != val && bottoms[i] != val)
                {
                    f = 0;
                    break;
                }
                if (tops[i] != val)
                    c1++;
                if (bottoms[i] != val)
                    c2++;
            }
            if (f)
                ans = min(ans, min(c1, c2));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};