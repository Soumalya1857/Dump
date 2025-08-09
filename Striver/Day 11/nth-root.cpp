class Solution {
public:
    
    double abso(double a)
    {
        return a < 0 ? -a : a;
    }
    
    double nthRoot(int x, int n)
    {
        int x1 = x;
        double low = 0, high = x1, mid=0;
        while(low < high)
        {
            if(abso(pow(mid,n) - x) <= 0.001) {break;}
            mid = (low+high)/2.0;
            cout << "low: " << low << " high: " << high << endl;
            if(pow(mid,n) > x) high = mid;
            else if(pow(mid,n) < x) low = mid;
            
        }
        
        return mid;
    }
    int mySqrt(int x) {
        
        return nthRoot(x,2);
    }
};

// prb: https://leetcode.com/problems/sqrtx/