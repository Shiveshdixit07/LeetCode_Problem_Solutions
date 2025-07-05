class Solution {
public:
    int ht[501];
    int findLucky(vector<int>& arr) {
        for(auto &e:arr)ht[e]++;
        for(int i=500;i>=1;i--)if(ht[i]==i){return i;}
        return -1;
    }
};