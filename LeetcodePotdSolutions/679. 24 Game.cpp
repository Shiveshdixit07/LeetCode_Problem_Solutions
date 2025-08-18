class Solution
{
    const double eps = 1e-6;

public:
    bool judgePoint24(vector<int> &cards)
    {
        vector<double> nums;
        for (auto &e : cards)
            nums.push_back(e);
        return dfs(nums);
    }

    bool dfs(vector<double> &vt)
    {
        if (vt.size() == 1)
        {
            if (abs(vt[0] - 24.0) <= eps)
                return 1;
            return 0;
        }
        int n = vt.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                vector<double> next;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                        next.push_back(vt[k]);
                }

                for (double val : compute(vt[i], vt[j]))
                {
                    next.push_back(val);
                    if (dfs(next))
                        return 1;
                    next.pop_back();
                }
            }
        }
        return 0;
    }

    vector<double> compute(double a, double b)
    {
        vector<double> arr;
        arr.push_back(a + b);
        arr.push_back(a - b);
        arr.push_back(b - a);
        arr.push_back(a * b);
        if (b >= eps)
            arr.push_back(a / b);
        if (a >= eps)
            arr.push_back(b / a);
        return arr;
    }
};