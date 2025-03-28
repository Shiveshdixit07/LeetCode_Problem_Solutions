class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &q)
    {
        vector<int> diff(nums.size() + 1);
        int sum = 0;
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (sum + diff[i] < nums[i])
            {
                if (k == q.size())
                    return -1;
                int l = q[k][0];
                int r = q[k][1] + 1;
                int v = q[k][2];
                diff[l] += v;
                diff[r] -= v;
                if (i > l && i <= r)
                    sum += v;
                k++;
            }
            sum += diff[i];
        }
        return k;
    }
};