class Solution {

    /**
     * @brief 
     * 
     * 
     * we want to break into 3 parts
     * so=> x x+1 x+2
     *  => 3x + (1+2)
     *  => i*x + (i-1) * ((i-1)+1) / 2
     * => i*x + i*(i-1)/2 = n
     * 
     * i*x should be n - i*(i-1)/2
     * 
     * and x should be a positive number
     */
private:
    bool isPossible(int n, int val){
        int remain = n - (val*(val-1))/2;
        if(((remain/val)*val == remain) && ((remain/val) >= 1)) return true;

        return false;
    }

public:
    int consecutiveNumbersSum(int n) {
        int count = 1;

        for(int val=2; ;val++){
            if(isPossible(n, val)){
                count++;
            }

            if( (val*(val-1))/2 > n) break; // val < sqrt(2N)
        }

        return count;
    }
};

// https://leetcode.com/problems/consecutive-numbers-sum/description/


// https://leetcode.com/problems/consecutive-numbers-sum/

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 1;
        for( int k = 2; k < sqrt( 2 * N ); k++ ) {
            if ( ( N - ( k * ( k - 1 )/2) ) % k == 0) count++;
        }
        return count;
    }
};

