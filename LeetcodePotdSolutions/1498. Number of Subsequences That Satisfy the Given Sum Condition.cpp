class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> pow2;
    void compute(int n) {
        pow2[0] = 1;
        pow2[1] = 2;
        for (int i = 2; i <= n; i++) {
            pow2[i] = (1LL * pow2[i - 1] * 2) % mod;
        }
    }
    int numSubseq(vector<int>& nums, int t) {
        int n = nums.size();
        pow2.resize(n + 1);
        compute(n);
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        int ans = 0;
        while (l <= r) {
            if (nums[r] + nums[l] > t) {
                r--;
                continue;
            }
            ans = (0LL + ans + pow2[r - l]) % mod;
            l++;
        }
        return ans;
    }
};