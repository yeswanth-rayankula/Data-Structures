class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        int sol=0,ans=0,year;
        for(auto i: logs)
        {
            mp[i[0]]++;
            mp[i[1]]--;
        }
        for(auto i: mp)
        {
            sol+=i.second;
            if(sol>ans)
            {
                ans=sol;
                year=i.first;
            }
        }
        return year;
    }
};