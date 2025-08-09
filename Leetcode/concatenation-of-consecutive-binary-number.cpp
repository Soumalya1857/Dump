/* 
problem: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
Solution: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/discuss/1037355/C%2B%2B-Super-Simple-Short-and-Easy-O(n)-Solution
*/

class Solution {
public:
    int concatenatedBinary(int n) {
        long long int res = 0, bitLen = 0, mod = 1e9+7;
        for(int i=1;i<=n;i++)
        {
            if((i & (i-1)) == 0)
            {
                // it's a power of two
                bitLen++;
            }
            
            res = (res << bitLen) % mod;
            res += i;
            res %= mod;
        }
        
        return res;
    }
};