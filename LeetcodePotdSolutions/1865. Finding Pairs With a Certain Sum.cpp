class FindSumPairs {
public:
    unordered_map<int, int> mp1, mp2;
    vector<int> b;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto& e : nums1)
            mp1[e]++;
        b = nums2;
        for (auto& e : nums2) {
            mp2[e]++;
        }
    }

    void add(int index, int val) {
        mp2[b[index]]--;
        b[index] += val;
        mp2[b[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (auto& [x, y] : mp1) {

            if (tot < x)
                continue;

            ans += (y * mp2[tot - x]);
        }
        return ans;
    }
};

