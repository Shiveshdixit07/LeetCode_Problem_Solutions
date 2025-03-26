class Solution
{
public:
    int minOperations(vector<vector<int>> &matrix, int x)
    {
        vector<int> temp;
        int rem = matrix[0][0] % x;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] % x != rem)
                {
                    return -1;
                }
                else
                {
                    temp.push_back(matrix[i][j]);
                }
            }
        }
        int result = 0;
        sort(temp.begin(), temp.end());
        int len = m * n;
        int mid = len / 2;
        int curr = temp[mid];
        for (int i = 0; i < len; i++)
        {
            if (curr != temp[i])
            {
                result += abs(temp[i] - curr) / x;
            }
        }
        return result;
    }
};