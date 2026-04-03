class Solution {
public:
    bool solve(long long m,vector<int>& piles,int h)
    {
        long long ans = 0;
        for(auto i: piles)
        {
            ans += (i/m)+((i%m)>=1 ? 1 : 0);
        }
        return ans <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int r=0,l=1,ans=0;
        for(auto i: piles)
        {
            r=max(r,i);
        }
        while(l<=r)
        {
            long long  m = l + (r - l)/2;
            if(solve(m,piles,h))
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