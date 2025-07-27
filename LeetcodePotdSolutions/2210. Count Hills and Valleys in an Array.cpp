class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        int l = nums[0];
        int i = 1;
        int m, r;
        while (i < n && nums[i] == nums[i - 1])
        {
            i++;
        }
        if (i >= n)
            return ans;
        m = nums[i];
        i++;
        while (i < n && nums[i] == nums[i - 1])
        {
            i++;
        }
        if (i >= n)
            return ans;
        r = nums[i];
        i++;
        if (m < l && m < r)
            ans++;
        else if (m > l && m > r)
            ans++;
        l = m;
        m = r;
        while (i < n)
        {
            while (i < n && nums[i] == m)
            {
                i++;
            }
            if (i >= n)
                return ans;
            r = nums[i];
            if (m < l && m < r)
                ans++;
            else if (m > l && m > r)
                ans++;
            l = m;
            m = r;
            i++;
        }
        return ans;
    }
};