class Solution
{
public:
    static bool cmp(vector<int> &p, vector<int> &q)
    {
        if (p[0] == q[0])
            return p[1] < q[1];
        return p[0] > q[0];
    }

    int numberOfPairs(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int n = points.size(), ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int temp = INT_MAX;
            for (int j = i + 1; j < n; j++)
            {
                if (points[j][1] >= points[i][1] && temp > points[j][1])
                {
                    ans++;
                    temp = points[j][1];
                }
            }
        }
        return ans;
    }
};
