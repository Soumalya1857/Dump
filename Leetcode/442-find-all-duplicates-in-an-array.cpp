class Solution {
private:
    int abso(int n){
        return n < 0 ? -n : n;
    }

public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int index = abso(nums[i]) - 1;
            nums[index] *= -1;

            if(nums[index] > 0){
                ans.push_back(index+1);
            }
        }

        return ans;



    }
};

// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/