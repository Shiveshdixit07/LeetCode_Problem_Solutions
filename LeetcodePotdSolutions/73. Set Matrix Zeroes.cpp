
class Solution
{
public:
    void setZeroes(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        bool f1 = 0;
        bool f2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 0)
            {
                f1 = 1;
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == 0)
            {
                f2 = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    mat[i][0] = mat[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mat[i][0] == 0 || mat[0][j] == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }
        if (f1)
        {
            for (int i = 0; i < n; i++)
            {
                mat[i][0] = 0;
            }
        }
        if (f2)
        {
            for (int j = 0; j < m; j++)
            {
                mat[0][j] = 0;
            }
        }
    }
};