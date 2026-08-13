// Time complexity O(N*L*L)
// Space complexity O(N*L)
// N-> No of words
// L-> Length of word

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        

        unordered_map<string,int> mp;
        int ans = 1;
        for(auto i: wordList)
        {
            mp[i]++;
        }
        if(mp[endWord]==0)
            return 0;
        queue<string> q;
        q.push(beginWord);



        while(!q.empty())
        {
            int n=q.size();
            
            while(n--)
            {
                string a=q.front();
                q.pop();

                for(int i=0;i<a.size();i++)
                {
                    char ch=a[i];
                    for(char j='a';j<='z';j++)
                    {
                        a[i]=j;
                        if(a==endWord)
                            return ans+1;
                        if(mp[a]>0)
                        {
                            q.push(a);
                            mp[a]--;
                        }
                    }
                    a[i]=ch;
                }
            }
            ans++;
        }
        return 0;
    }
};