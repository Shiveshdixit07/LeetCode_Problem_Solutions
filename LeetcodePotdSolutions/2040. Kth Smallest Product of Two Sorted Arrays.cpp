class Solution {
public:
#define ll long long
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        ll low = -1e10;
        ll high = 1e10;
        while (low < high) {
            ll mid = low + (high - low) / 2;
            if (Product(nums1, nums2, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    ll Product(vector<int>& nums1, vector<int>& nums2, ll target) {
        ll count = 0;
        int n = nums1.size();
        int m = nums2.size();
        for (int num1 : nums1) {
            if (num1 == 0) {
                if (target >= 0)
                    count = count + m;
                continue;
            }
            int low = 0;
            int high = m;
            while (low < high) {
                int mid = low + (high - low) / 2;
                ll multiply = 1LL * num1 * nums2[mid];
                if (multiply <= target) {
                    if (num1 > 0)
                        low = mid + 1;
                    else
                        high = mid;
                } else {
                    if (num1 > 0)
                        high = mid;
                    else
                        low = mid + 1;
                }
            }
            count += (num1 > 0) ? low : (m - low);
        }
        return count;
    }
};