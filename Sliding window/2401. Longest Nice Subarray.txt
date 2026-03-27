class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int sol = 0, sum =0, ans=0,j=0;

        for(int i=0;i<nums.size();i++)
        {
           sum = sum + nums[i];
           sol = (sol | nums[i]);
           while(sum!=sol && j<i)
           {
              sol = (sol & (~nums[j]));
              sum = sum -nums[j]; 
              sol = (sol | nums[i]);
              j++;
           }
           ans = max(ans,i-j+1);
        }

        return ans;
    }
};
