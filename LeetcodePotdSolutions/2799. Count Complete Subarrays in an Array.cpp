class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        int i = 0;
        unordered_set<int> st;
        for (auto &x : nums)
            st.insert(x);
        int d = st.size();
        unordered_map<int, int> mp;
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            mp[nums[j]]++;
            if (mp[nums[j]] == 1)
                c++;
            while (i <= j && c == d)
            {
                ans += (n - j);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    c--;
                i++;
            }
        }

        return ans;
    }
};