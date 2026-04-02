class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long sol = 0,count = 0;
        for(int i=0;i<nums.size();i++)
        {
            sol = sol ^ nums[i];
        }
        while(sol)
        {
            if((sol&1) !=0)
                break;
            count ++;
            sol = (sol>>1);
        }
        int a=0,b=0;
        for(auto i: nums)
        {
            if(1&(i>>count))
            {
                a = a^i;
            }
            else{
                b = b^i;
            }
        }
        return {a,b};
    }
};



// 3 - 1011
// 5 - 1101

// x - 0110


// num & (1<<3)