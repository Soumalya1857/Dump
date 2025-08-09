class Solution {
public:
    double myPow(double x, int n) {
        
        double res = 1.0;
        int i = n;
        while(n)
        {
            if(n & 1) res = res * x;
            
            x *= x;
            n /= 2;
        }
        
        if(i>=0) return res;
        else return 1.0/res;
    }
};

// solution: https://leetcode.com/problems/powx-n/submissions/