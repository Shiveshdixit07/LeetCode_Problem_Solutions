class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            temp[i][m - 1] = mat[i][m - 1] == 0 ? 0 : 1;
            for (int j = m - 2; j >= 0; j--)
            {
                temp[i][j] = mat[i][j] == 0 ? 0 : temp[i][j + 1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int mini = temp[i][j];
                for (int d = i; d < n; d++)
                {
                    if (temp[d][j] == 0)
                        break;
                    mini = min(mini, temp[d][j]);
                    ans += mini;
                }
            }
        }
        return ans;
    }
};