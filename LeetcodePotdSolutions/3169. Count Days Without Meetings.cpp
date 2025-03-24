class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& I) {
        if(I.size()==1)return I;
        vector<vector<int>>ans;
        sort(I.begin(),I.end());
        for(int i=0;i<I.size();i++)
        {
            if(ans.empty() || ans.back()[1]<I[i][0])
            {
                ans.push_back(I[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],I[i][1]);
            }
            
        }       
       return ans;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        auto t=merge(meetings);
        int ans=max(0,t[0][0]-1);
        for(int i=1;i<t.size();i++)
        {
            ans+=(t[i][0]-t[i-1][1]-1);
        }
        ans+=max(0,days-t.back()[1]);
        return ans;
    }
};