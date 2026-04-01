class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int sol = 0;
        for(int i=0;i<32;i++)
        {
            int count = 0;
            for(int j=0;j<nums.size();j++)
            {
                if((1<<i)&nums[j])
                {
                    count++;
                }
            }
            if(count%3)
            {
                sol =(sol | (1<<i));
            }
        }
        return sol;
    }
};