
// Time complexity O(N logN)+ O(N)
// Space complexity O(1)

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);

        int end = pairs[0][1];
        int pair = 1,sol=0;
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[i][0]>end)
            {
                cout<<end<<" ";
                end = pairs[i][1];
                pair++;
            }


        }
        return pair;
        
    }
};