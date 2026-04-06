class Solution {
public:
    bool solve(int dist, vector<int>& stalls, int k) {
        int count = 1;
        int st = stalls[0];

        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - st >= dist) {
                count++;
                st = stalls[i];
            }
        }
        return count >= k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int l = 1;
        int r = stalls.back() - stalls.front();
        int ans = 0;

        while(l <= r) 
        {
            int m = l + (r - l) / 2;

            if(solve(m, stalls, k)) {
                ans = m;
                l = m + 1; 
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};