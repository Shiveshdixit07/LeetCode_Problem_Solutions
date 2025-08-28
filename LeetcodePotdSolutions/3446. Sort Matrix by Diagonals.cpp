class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> temp;
            int I = i;
            int J = 0;
            while (I < n && J < n)
            {
                temp.push_back(grid[I][J]);
                I++;
                J++;
            }
            sort(temp.begin(), temp.end(), greater<int>());
            I = i;
            J = 0;
            int idx = 0;
            while (I < n && J < n)
            {
                grid[I][J] = temp[idx++];
                I++;
                J++;
            }
        }
        for (int j = 1; j < n; j++)
        {
            int I = 0;
            int J = j;
            vector<int> temp;
            while (I < n && J < n)
            {
                temp.push_back(grid[I][J]);
                I++;
                J++;
            }
            sort(temp.begin(), temp.end());
            I = 0;
            J = j;
            int idx = 0;
            while (I < n && J < n)
            {
                grid[I][J] = temp[idx++];
                I++;
                J++;
            }
        }
        return grid;
    }
};