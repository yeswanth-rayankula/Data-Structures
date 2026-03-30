class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<char,int> mp;
        int j=0,ans=0,sol=0;
        char ch ;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            sol = max(sol, mp[s[i]]);
            while(((i-j+1)-sol) > k)
            {
                mp[s[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};