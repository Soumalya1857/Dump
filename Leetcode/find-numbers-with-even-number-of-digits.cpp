class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums){
            int count = 0;
            while(num>0){
                num /= 10;
                count++;
            }
            
            if(!(count & 1)) ans++;
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
