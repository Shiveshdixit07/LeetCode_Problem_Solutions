class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            if (nums[j] - nums[i] == 1)
                ans = max(ans, j - i + 1);
            if (nums[j] - nums[i] <= 1)
                j++;
            else
                i++;
        }
        return ans;
    }
};