class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int r = cardPoints.size()-k,j=0, ans=INT_MAX,sum=0, sol=0;
        cout<<r;
        for(int i=0;i<cardPoints.size();i++)
        {
            sol += cardPoints[i]; 
            sum += cardPoints[i];
            if((i-j+1)==r)
            {
               ans=min(ans, sum);
               sum=sum-cardPoints[j];
               j++;   
            }
        }
        return r==0 ? sol : sol - ans;
    }
};