class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> temp(n);
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {

                prev = i;
            }
            if (prev >= 0 && abs(prev - i) <= k) {
                temp[i] = 1;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == key) {

                prev = i;
            }
            if (prev >= 0 && abs(prev - i) <= k) {
                temp[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
            if (temp[i])
                ans.push_back(i);

        return ans;
    }
};