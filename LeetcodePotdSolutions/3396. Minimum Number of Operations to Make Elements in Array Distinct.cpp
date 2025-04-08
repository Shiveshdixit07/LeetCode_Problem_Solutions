class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1)
                count++;
        }
        int ans = 0;
        if (count == 0)
            return ans;
        for (int i = 0; i < n;)
        {
            ans++;
            for (int j = 0; j < 3 && i < n; j++, i++)
            {
                if (mp[nums[i]] > 1)
                    count--;
                mp[nums[i]]--;
                if (count == 0)
                    return ans;
            }
        }
        return ans;
    }
};