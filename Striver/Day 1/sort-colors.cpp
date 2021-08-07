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