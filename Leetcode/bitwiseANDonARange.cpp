/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        long long step = 1;
        while(m != n)
        {
            m = m >> 1;
            n = n >> 1;
            step = step << 1;
        }
        
        return m * step;
    }
};

/*
First, Let's say some rules: 1) If two numbers are equal, no numbers will be between them. 
2) If Two numbers are not Equal, The consecutive number between them Will contain ZERO at each digit, 
thus their bitwise AND will be ZERO.

Before going into the example, We should explain the simple algorithm above.

1) Each division by two means remove a binary digit from the right of the numbers.
 (This is how division by two means in binary). 2) Each time we divide,
  we double the step variable. 
  Simple, the step variable is more like a counter that holds the top most digit value 
  just before the two numbers became equal.
*/