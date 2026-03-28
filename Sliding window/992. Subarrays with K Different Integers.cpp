class Solution {
public:
    int solve(vector<int>& nums,int k)
    {
        int j=0,sol=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            while(mp.size()>k)
            {
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
            sol+=(i-j+1);
        }
        return sol;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};