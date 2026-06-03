class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        

        map<int,int> mp;
        vector<vector<int>> sol;
        for(auto i: intervals)
        {
            mp[i[0]]++;
            mp[i[1]]--;
        }
        mp[newInterval[0]]++;
        mp[newInterval[1]]--;

        int c=0,s=0;
        for(auto i: mp)
        {
            if(c==0)
            {
                s=i.first;
            }
            c+=i.second;
            if(c==0)
            {
                sol.push_back({s,i.first});
                s=0;
            }
        }
        return sol;
    }
};