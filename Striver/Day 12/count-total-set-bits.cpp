class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    // int count1s(int bitPos, int setUpto)
    // {
    //     int res = 0;
    //     res += (bitPos)
    // }
    int countSetBits(int n)
    {
        // Your logic here
        // get n as sum of 2^i s
        // each 2^i-1 contains i*(2^i-1) set bits
        // int setUpto = 0;
        // for(int i=31;i>=0;i--)
        // {
        //     if(n & (1<<i))
        //     {
        //         count += count1s(i+1);
        //         setUpto++;
        //     }
        // }
        
        vector<int> dp(n+5,0); // no of setbits of number i
        int count = 0;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        
        for(int i=4;i<=n+4;i+=2)
        {
            dp[i] = dp[i/2];
            dp[i+1] = dp[i] + 1;
        }
        
        // dp[i] = dp[i/2] + (i%2);
        
        for(int i=0;i<=n;i++) count += dp[i];
        
        return count;
    }
    
    
    // for a num a have 2 bits and a is even
    // 2*a is basically a<<1 => means set bits will be equal
    // 2*a+1 is a<<1+1 no of setbits = 1 + setbits
    // youtube: https://www.youtube.com/watch?v=awxaRgUB4Kw
};

// another approach: https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n-set-2/