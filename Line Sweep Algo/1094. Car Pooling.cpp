class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        int count =0;
        for(auto i: trips)
        {
            mp[i[1]]+=i[0];
            mp[i[2]]-=i[0];
        }
        for(auto i: mp)
        {
            count+=i.second;
            if(count>capacity)
                return 0;
        }
        return 1;
    }
};