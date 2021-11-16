class Solution {
public:
    
    // not same as josephus problem
   
    int lastRemaining(int n) {
        
        if(n == 1) return 1;
        return 2*(n/2 - lastRemaining(n/2)+1);
    }
};

// https://leetcode.com/problems/elimination-game/
// https://leetcode.com/problems/elimination-game/discuss/1270210/Let's-form-the-Recurrence-Relation!