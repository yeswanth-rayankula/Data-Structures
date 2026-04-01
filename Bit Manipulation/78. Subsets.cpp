class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> sol;
        int n=nums.size();
        n=(1<<n);
        // n=pow(2,n);
        // pow(2,n) == (1<<n)
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<nums.size();j++)
            {
               if(i&(1<<j))
               {
                 temp.push_back(nums[j]);
               }
            }
            sol.push_back(temp);
        }
        return sol;
    }
};

