class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {       
            x = 1/x;
        }
        return solve(x, n);  
    }

    double solve(double x, long long n) {
        if(n == 0) 
            return 1;
        if(n == 1) 
            return x;
        double t = solve(x, n/2);

        if(n % 2 != 0)
            return t*t*x;
        return t*t;
    }
};