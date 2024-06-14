class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int candidate1=0, count1=0;
        int candidate2=0,count2=0;

        candidate1 = nums[0];
        for(int num : nums)
        {
            if(num == candidate1)
            {
                count1++;
            }
            else if(num == candidate2)
            {
                count2++;
            }
            else if(count1 == 0)
            {
                count1 = 1;
                candidate1 = num;
            }
            else if(count2 == 0)
            {
                count2 = 1;
                candidate2 = num;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1=0,count2=0;
        for(int num : nums)
        {
            if(num == candidate1) count1++;
            if(num == candidate2) count2++;
        }
        int size = nums.size();
        vector<int> ans;
        if(count1 > size/3) ans.push_back(candidate1);
        if(candidate1 != candidate2) if(count2 > size/3) ans.push_back(candidate2);

        return ans;
    }
};

// prb: https://leetcode.com/problems/majority-element-ii/submissions/
// soln: https://leetcode.com/problems/majority-element-ii/discuss/1389108/O(n)-boyer-moore-majority-algorithm-in-java
// https://www.youtube.com/watch?v=yDbkQd9t2ig&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=16


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN, candidate2 = INT_MIN;

        int count1 = 0, count2 = 0;
        int n = nums.size();


        for(int i=0; i<n; i++){
            if(count1 == 0 && nums[i] != candidate2){
                candidate1 = nums[i];
                count1 = 1;
            } else if(count2 == 0 && nums[i] != candidate1){
                candidate2 = nums[i];
                count2 = 1;
            } else if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
            else{
                count1--;
                count2--;
            }
        }

        int minNeeded = n/3 + 1;
        count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
        }

        vector<int> ans;
        if(count1 >= minNeeded) ans.push_back(candidate1);
        if(count2 >= minNeeded) ans.push_back(candidate2);


        return ans;
    }
};

// https://www.youtube.com/watch?v=vwZj1K0e9U8&t=0s

// ================================= LEETCODE CODE

