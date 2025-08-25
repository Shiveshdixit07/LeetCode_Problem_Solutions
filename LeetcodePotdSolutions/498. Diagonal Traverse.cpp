class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vt(n + m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vt[i + j].push_back(mat[i][j]);
            }
        }
        bool f = 1;
        vector<int> ans;
        for (int i = 0; i < n + m - 1; i++)
        {
            int j = f ? vt[i].size() - 1 : 0;
            for (j; f ? (j >= 0) : (j < vt[i].size()); f ? j-- : j++)
            {
                ans.push_back(vt[i][j]);
            }
            f = 1 - f;
        }
        return ans;
    }
};