class Solution {
public:
    int possibleStringCount(string& word) {
        int ans = 1;
        char prev = '0';
        int cnt = 0;
        for (auto& e : word) {
            if (e != prev) {
                ans += max(0, cnt - 1);
                prev = e;
                cnt = 1;
            } else
                cnt++;
        }
        ans += max(0, cnt - 1);
        return ans;
    }
};