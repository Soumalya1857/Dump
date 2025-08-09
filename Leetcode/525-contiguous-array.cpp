class Solution {
public:
// this was a thinker
// initially you will think a 2 pointer approach will be a best one
// but think of the TC [0,1,0,1]

// best thing I came up with is prefix sum hehe
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> mp; // val, index
        // val only can be -1, 1, 0

        int prefix = 0;
        int maxLen = 0;

        for(int i=0; i<nums.size();i++){
            if(nums[i] == 1) prefix++;
            if(nums[i] == 0) prefix--;

            if(prefix == 0){
                maxLen = max(maxLen, i+1);
            }


            if(mp.find(prefix) == mp.end()){
                mp[prefix] = i;
            }else{
                int len = i - mp[prefix];
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;


        // int left = 0, right = 0, count = 0;
        // bool isStart = true;

        // int maxLen = 0;

        // while(right < nums.size()){

        //     if(nums[right] == 1) count++;
        //     if(nums[right] == 0) count--;

        //     while(count == 0 && left <= right){
        //         int len = right - left + 1;
        //         if(len > maxLen){
        //             maxLen = len;
        //         }

        //         if(nums[left] == 1) count--;
        //         if(nums[left] == 0) count++;
        //         left++;
        //     }

        //     right++;
        // }

        // return maxLen;
    }
};

// https://leetcode.com/problems/contiguous-array/
// https://leetcode.com/problems/contiguous-array/solutions/1743341/c-simplest-solution-optimization-from-brute-force-one-pass/