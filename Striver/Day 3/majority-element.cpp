class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // moores voting algorithm
        
        int count = 0;
        int candidate = 0;
        
        for(int num: nums)
        {
            if(count == 0) candidate = num; // count = 0 means majority element == sum(minority element)
            // and as we know we always will have a majority element
            // there has to be a majority element after when count becomes 0
            
            if(candidate == num) count++; // ++ if majority found
            else count--;                // -- if minority found
        }

        // traverse the array agian to check candidate is actually the majority one
        // necessary if noone in the array is majority
        count = 0;
        for(int num : nums){
            if(num == candidate) count++;
        }
        
        return count > nums.size()/2 ? candidate : -1;
    }
};

// problem: https://leetcode.com/problems/majority-element/
// youtube: https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=16