// o(n) time and o(n) solution

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size(); // gurantees that ans can be max upto n+1
        vector<bool> isPresent(n+2, false); // keep map which values we have seen

        for(int num : nums){
            if(num > 0 && num < n+1){
                isPresent[num] = true;
            }
        }

        for(int i=1; i<n+2; i++){
            if(isPresent[i] == false){ // if false means we have not seen the number
                return i;
            }
        }

        return n+1;
    }
};

// https://leetcode.com/problems/first-missing-positive/

// sol: https://leetcode.com/problems/first-missing-positive/editorial/

// O(n) and O(1) space solution

// manipulate the array data to get rid of the extra array space

/*
Initialize a variable n to the length of nums, and a boolean contains1 to false.

Traverse nums, check whether 1 occurs, and replace negative numbers, zeros, and numbers larger than n with 1. For each element in nums:

If the element equals 1, set contains1 to true.
If the element is less than or equal to 0 or greater than n, replace it with 1.
If the original nums array does not contain 1, return 1.

Traverse nums using a for loop from i equals 0 to n. When value is encountered, flip the sign of the number at index value to negative to indicate that it is present in the array. Use absolute value to prevent duplicate occurrences of value from flipping the sign back to positive.

Set an integer value to the absolute value of nums[i].
If value equals n, we use index 0 to save information about the presence of the number n since index n is not available. Set nums[0] to the negative of the absolute value of nums[0].
Otherwise, we use index value to store information about the presence of the number value. Set nums[value] to the negative of the absolute value of nums[value].
Find the smallest missing positive number:

Iterate through the integers 1 to n using iterator i. If nums[i] is positive, return i.
If nums[0] is greater than 0 return n.

If nums contains all elements 1 to n, return n + 1 as the smallest missing positive number.
*/