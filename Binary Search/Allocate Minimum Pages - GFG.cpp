class Solution {
  public:
    bool solve(int m,vector<int>& arr,int k)
    {
        int sum=0,count=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum>m)
            {
                sum=arr[i];
                count++;
            }
        }
        return count>=k?1:0;
    }
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size())
            return -1;
        // code here
        int l=0,r=0;
        for(auto i: arr)
        {
            r+=i;
            l=max(l,i);
        }
        while(l<=r)
        {
            int m=l+ (r-l)/2;
            if(solve(m,arr,k))
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return l;
    }
};