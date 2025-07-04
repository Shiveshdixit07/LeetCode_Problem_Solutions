class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        if (k == 1)
            return 'a';
        long long len = 2;
        int i = 0;
        for (len; len < k; len *= 2)
            i++;
        return ((kthCharacter(k - len / 2, op) - 'a' + op[i]) % 26 + 'a');
    }
};