class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st;
        int maxi = INT_MIN;
        int ans = 0;
        bool f = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                maxi = max(maxi, nums[i]);
            }
            else
            {
                if (!st.count(nums[i]))
                {
                    ans += nums[i];
                    f = 1;
                    st.insert(nums[i]);
                }
            }
        }

        if (f == 0)
            return maxi;
        return max(ans, maxi);
    }
};