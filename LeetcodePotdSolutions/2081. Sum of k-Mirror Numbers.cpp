class Solution {
public:
#define ll long long
    bool isPallindrome(string& s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return 0;
        }
        return 1;
    }
    string Kbase(ll nums, int k) {
        string ans = "";
        while (nums > k - 1) {
            ans += (nums % k);
            nums /= k;
        }
        ans += nums;
        return ans;
    }
    long long kMirror(int k, int n) {
        int L = 1;
        ll ans = 0;
        while (n > 0) {
            int half = (L + 1) / 2;

            ll min = pow(10, half - 1);
            ll max = pow(10, half) - 1;
            for (int i = min; i <= max; i++) {
                string num = to_string(i);
                string rev = num;
                reverse(rev.begin(), rev.end());
                if (L & 1) {
                    num += rev.substr(1);
                } else {
                    num += rev;
                }
                ll nums = stoll(num);
                string kbase = Kbase(nums, k);
                if (isPallindrome(kbase)) {

                    ans += nums;
                    n--;
                    if (n == 0)
                        break;
                }
            }
            L++;
        }
        return ans;
    }
};