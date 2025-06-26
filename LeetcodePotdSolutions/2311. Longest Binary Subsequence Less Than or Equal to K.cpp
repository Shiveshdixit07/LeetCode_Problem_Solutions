class Solution {
public:
    int longestSubsequence(string& s, int k) {
        int n = s.length();
        int ans = 0;
        for (int i = n - 1; i >= 0 && k >= 0; i--) {
            if (s[i] == '0')
                ans++;
            else {
                if ((n - i - 1) < 33 && k - (1LL << (n - i - 1)) >= 0) {
                    ans++;
                    k -= (1 << (n - i - 1));
                }
            }
        }
        return ans;
    }
};