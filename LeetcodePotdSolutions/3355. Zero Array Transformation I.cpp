class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &qq)
    {
        int n = nums.size();
        vector<int> arr(n + 1, 0);
        for (auto &q : qq)
        {
            arr[q[0]]++;
            if (q[1] + 1 < n)
                arr[q[1] + 1]--;
        }
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            c += arr[i];
            if (nums[i] > c)
                return 0;
        }
        return 1;
    }
};