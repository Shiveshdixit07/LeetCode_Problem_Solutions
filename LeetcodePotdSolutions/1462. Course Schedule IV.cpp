class Solution
{
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &pr, vector<vector<int>> &q)
    {
        vector<bool> ans;
        vector<vector<bool>> g(n, vector<bool>(n));
        for (auto &x : pr)
        {
            g[x[0]][x[1]] = 1;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (g[i][j])
                        continue;
                    if (g[i][k] && g[k][j])
                    {
                        g[i][j] = 1;
                    }
                }
            }
        }
        for (auto &x : q)
        {
            if (g[x[0]][x[1]])
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};