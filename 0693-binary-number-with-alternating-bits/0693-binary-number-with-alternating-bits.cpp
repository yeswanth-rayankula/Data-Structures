class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n && n>>1)
        {
            if((n&1)==((n>>1)&1))
                return false;
            n=n>>1;
        }
        return true;
    }
};