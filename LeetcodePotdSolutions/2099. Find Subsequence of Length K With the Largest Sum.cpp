class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end(), greater<>());

        sort(temp.begin(), temp.begin() + k, cmp);
        for (int i = 0; i < k; i++)
            ans.push_back(temp[i].first);
        return ans;
    }
};