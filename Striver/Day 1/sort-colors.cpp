class Solution {
public:
    void sortColors(vector<int>& nums) {
        // inplace sorting
        // counting sort only
        
        int count0 = 0, count1 = 0, count2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0) count0++;
            if(nums[i] == 1) count1++;
            if(nums[i] == 2) count2++;
        }
        
        nums.clear();
        for(int i=0;i<count0;i++) nums.push_back(0);
        for(int i=0;i<count1;i++) nums.push_back(1);
        for(int i=0;i<count2;i++) nums.push_back(2);
    }
};

// ques: https://leetcode.com/problems/sort-colors/
// soln: https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2

// good solution memory based
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end()); // 这里不用库函数来排序。
        // 因为都是有多个重复的元素，因此我们可以继续用桶的思想去做。
        unordered_map<int, int> nums_map; // 还是会比map更快一些，因为它会对key排序。
        for (const auto &a:nums)
        {
            ++nums_map[a];
        }
        int j = 0;
        for (int k = 0; k < 3; k++)
        {
            for (int i = 0; i < nums_map[k]; i++)
            {
                nums[j++] = k;
            }
        }
    }
};

//===================================

/*
Approach : Dutch National Flag algorithm
The Dutch National Flag algorithm, also known as 3-way partitioning, is an algorithm for sorting an array containing three distinct values. The algorithm was designed to solve the problem of sorting an array containing only 0s, 1s, and 2s, which is similar to the problem in the given question.

The algorithm works by maintaining three pointers: low, mid, and high. The low pointer points to the beginning of the array, the high pointer points to the end of the array, and the mid pointer starts at the beginning of the array and moves through it.

The idea behind the algorithm is to keep all the 0s before the low pointer, all the 2s after the high pointer, and all the 1s between the low and high pointers. The algorithm moves the mid pointer through the array, comparing the value at each position with 1. If the value is 0, the element is swapped with the element at the low pointer, and the low and mid pointers are incremented. If the value is 2, the element is swapped with the element at the high pointer, and the high pointer is decremented. If the value is 1, the mid pointer is simply incremented.

The algorithm terminates when the mid pointer crosses the high pointer, indicating that all the elements have been processed and the array is sorted.

The Dutch National Flag algorithm is called one-pass because it sorts the array in a single pass through the elements. The time complexity of the algorithm is O(n), where n is the size of the array.

Complexity
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};