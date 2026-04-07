class Solution {
public:
    bool solve(int m, vector<int>& nums, int k) {
        int sum = 0, count = 0;

        for (auto i : nums) {
            sum += i;
            if (sum > m) {
                sum = i;
                count++;
            }
        }

        return count + 1 <= k;  
    }

    int splitArray(vector<int>& nums, int k) {
        int i = 0, j = 0;

        for (auto x : nums) {
            i = max(i, x); 
            j += x;        
        }

        while (i <= j) {
            int m = i + (j - i) / 2;

            if (solve(m, nums, k)) {
                j = m - 1;  
            } else {
                i = m + 1;
            }
        }

        return i;
    }
};