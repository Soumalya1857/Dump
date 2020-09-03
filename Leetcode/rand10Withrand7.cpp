// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

##################################### NOT ACCEPTED ############

class Solution {
public:
    int rand10() {
        
        int row = rand7();
        int col = rand7();
        
        int ans = col + (row-1)*7;
        
        return (ans>=40) ? rand10() : 1+ ans%10;
    }
};


/**

https://leetcode.com/problems/implement-rand10-using-rand7/


https://leetcode.com/problems/implement-rand10-using-rand7/discuss/816210/Python-rejection-sampling-2-lines-explained
*/


#########################  NOT ACCEPTED #########################


class Solution {
public:
    int rand10() {
     
        int arr[8] = {0,8,9,10,-1,-1,-1,-1};
        int num = rand7();
        if(arr[num] == -1) return rand7();
        else return arr[num];
    }

};

############################## NOT ACCEPTED ###########################




class Solution {
public:
    int rand10() {
     
        int arr[8] = {0,1,1,-1,-1,-1,-1,-1};
        int num = rand7();
        if(arr[num] == -1) return rand7();
        else return (rand7()%3 + 8);
    }
};


################################# ACCEPTEDDDDDD XDDD #############################

class Solution {
public:
    int rand10() {
        
        
        int row, col, ans = 1000;
        while(ans > 40)
        {
            row = rand7();
            col = rand7();
            ans = col + (row-1)*7;
        }
        
        return 1 + (ans-1)%10;
        
    }
};
