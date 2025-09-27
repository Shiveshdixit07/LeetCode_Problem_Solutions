class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &p)
    {
        double ans = 0;
        int n = p.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                {
                    auto first = p[i];
                    auto second = p[j];
                    auto third = p[k];
                    ans =
                        max(ans, 0.5 * abs(first[0] * (second[1] - third[1]) +
                                           second[0] * (third[1] - first[1]) +
                                           third[0] * (first[1] - second[1])));
                }
        return ans;
    }
};