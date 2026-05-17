class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int l=INT_MAX,count=0;
        map<int,int> mp;
        for(auto i: ranges)
        {   
            l=min(l,i[0]);
            mp[i[0]]++;
            mp[i[1]+1]--;
        }
        if(l>left)
            return false;
        for(int i=l;i<=right;i++)
        {
            count+=mp[i];
            if(count<=0 && i>=left && i<=right)
            {
                return false;
            }
        }
        return 1;
    }
};