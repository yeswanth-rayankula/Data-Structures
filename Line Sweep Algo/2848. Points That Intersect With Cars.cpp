class Solution {
public:
    int numberOfPoints(vector<vector<int>>& logs) {
        map<int,int> mp;
        int m=0,ans=0,sol=0;

        for(auto i: logs)
        {
            m=max(m,i[1]);
            mp[i[0]]++;
            mp[i[1]+1]--;
        }
        for(int i=1;i<=m;i++)
        {
            sol+=mp[i];
            if(sol>0)
            {
                ans++;
            }
        }
        return ans;
    }
};