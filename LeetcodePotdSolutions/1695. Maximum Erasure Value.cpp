class Solution
{
public:
    int mp[10001];
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 0;
        int ans = 0, sum = 0;
        while (j < n)
        {
            mp[nums[j]]++;
            sum += nums[j];
            if (mp[nums[j]] > 1)
                cnt++;
            while (i <= j && cnt > 0)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 1)
                    cnt--;
                sum -= nums[i];
                i++;
            }
            ans = max(ans, sum);
            j++;
        }
        return ans;
    }
};