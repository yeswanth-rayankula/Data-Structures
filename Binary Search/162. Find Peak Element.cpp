class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int i=1,j=nums.size()-1;
        if(nums.size()==1)
            return 0;
        if(nums.size()>=2)
        {
            int n=nums.size();
            if(nums[0]>nums[1])
                return 0;
            else if(nums[n-1]>nums[n-2])
                return n-1;
        }
        while(i<=j)
        {
            int m=(i+j)/2;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
                return m;
            if(nums[m]>nums[m-1] && nums[m]<nums[m+1])
                i=m+1;
            else
                j=m-1;
        }
        return -1;
    }
};