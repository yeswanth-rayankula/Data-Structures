// Time Complexity O(nlogn + n*2004) -> O(nlogn)
// Space Complexity O(n*2004) -> O(n)


class Solution {
public:
    bool static cmp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
    int solve(int i,int end,vector<vector<int>>& pairs,vector<vector<int>>& dp)
    {
        if(i>=pairs.size())
            return 0;
        int take = 0, ntake =0;
        if(dp[i][end+1001]!=-1)
            return dp[i][end+1001];
        if(i==0 || pairs[i][0]>end)
        {
            take =1+ solve(i+1,pairs[i][1],pairs,dp);
            ntake = solve(i+1,end,pairs,dp);
        }
        else
            ntake = solve(i+1,end,pairs,dp);
        return dp[i][end+1001]=max(take,ntake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int n=pairs.size();
        vector<vector<int>> dp(n,vector<int>(2004,-1));
        return solve(0,-1001,pairs,dp);
    }
};