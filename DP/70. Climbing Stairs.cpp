class Solution {
public:
    int solve(int n,vector<int>& dp)
    {
        if(n==1 || n==0)
            return 1;
        if(n==2)
            return 2;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        if(n==1 || n==0)
            return 1;
        if(n==2)
            return 2;
        int prev = 1,sol=0;
        int prev2 = 2;
        for(int i=3;i<=n;i++)
        {
            sol= prev+prev2;
            prev = prev2;
            prev2 =sol;
        }
        return sol;
        // return solve(n,dp);
    }
};