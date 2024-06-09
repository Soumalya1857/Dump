
#include <bits/stdc++.h>
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // ask the question starting from 1, if it's available or not
        int numToSearch = 1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > numToSearch){
                return numToSearch;
            }else if(nums[i] == numToSearch){
                numToSearch++;
            }
        }

        return numToSearch;
    }
};

// nlogn solution

// https://leetcode.com/problems/first-missing-positive/