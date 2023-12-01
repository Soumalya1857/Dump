class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(!(k&1)) return -1;
        if(k % 5 == 0) return -1;

        int lastRemainder = 1;
        if(lastRemainder % k == 0) return 1;

        for(int i = 1; i<100001; i++){
            lastRemainder = ((((lastRemainder%k) * (10 % k)) % k) + 1)%k;
            if(lastRemainder == 0) return i+1;
        }

        return -1;

    }
};

// https://leetcode.com/problems/smallest-integer-divisible-by-k/