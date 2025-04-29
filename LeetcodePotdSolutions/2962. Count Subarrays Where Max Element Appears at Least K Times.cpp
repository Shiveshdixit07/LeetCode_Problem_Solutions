class Solution
{
public:
#define ll long long
    long long countSubarrays(vector<int> &nums, int k)
    {
        ll maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int cnt = 0;
        ll ans = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == maxi)
                cnt++;
            while (i <= j && cnt >= k)
            {
                ans += (n - j);
                if (nums[i] == maxi)
                {
                    cnt--;
                }

                i++;
            }
        }
        return ans;
    }
};