class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &d)
    {
        int ans = 0;
        int mx = INT_MIN;
        for (auto x : d)
        {
            int l = x[0];
            int b = x[1];
            int diag2 = l * l + b * b;
            if (diag2 > mx)
            {
                mx = diag2;
                ans = l * b;
            }
            else if (diag2 == mx)
            {
                ans = max(ans, l * b);
            }
        }
        return ans;
    }
};