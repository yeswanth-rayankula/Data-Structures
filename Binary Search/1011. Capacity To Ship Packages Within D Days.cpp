class Solution {
public:
    bool solve(int m,vector<int>& weights,int days)
    {
        int sum = 0,count =0;
        for(auto i: weights)
        {
            if((sum+i)<=m)
            {
                sum += i;
            }
            else
            {
                sum = i;
                count ++;
            }
        }
        if(sum)
            count ++;
        return count<=days ? 1 : 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0, r=0;
        for(int i=0;i<weights.size();i++)
        {
            l =max(l,weights[i]);
            r +=weights[i];
        }
        while(l<=r)
        {
            int m = (l+r)/2;
            if(solve(m,weights,days))
            {
                r=m-1;
            }
            else
            {
                l=m+1; 
            }
        }
        return l;
    }
};