class Solution {
    // recusive binary search (maybe)
    // count number of deviations
    // and take care accordingly

    int getVal(vector<int> &nums, int index){
        if(index < 0) return INT_MIN;
        if(index >= nums.size()) return INT_MAX;
        return nums[index];
    }

    int solve(vector<int> &nums, int start, int end){
        if(start > end || start < 0 || end >= nums.size()) return 0;

        int mid = (start + end)/2;
        return !(getVal(nums, mid-1) <= getVal(nums, mid) && getVal(nums, mid) <= getVal(nums, mid+1)) 
                    + !(getVal(nums, mid-1) <= getVal(nums, mid+1))
                    + solve(nums, mid+1, end) + solve(nums, start, mid-1);
    }
public:
    bool checkPossibility(vector<int>& nums) {
        
        if(nums.size() <= 1) return true;

        int val = solve(nums, 0, nums.size()-1);
        cout << val << endl;

        if(val != 3 && val != 0 && val != 2) return false;
        else {
            return true;
        }

        // scenarios:

        //  1 4 5 3 6 7 = 2 true
        // 4 2 3 => 1 => false
        // 4 5 1 => 1 => false
        // 4 2 3 1 = 4 => false
    }
};

// https://leetcode.com/problems/non-decreasing-array/description/


// another easier approach is to nikalofy length of LIS, 
// if LIS >=n-1 true
// else false
// o(n^2) => same as brute force
class Solution {
private:
    int lis(vector<int> &nums, int prev, int index, vector<vector<int>> &dp){
        if(index >= nums.size()) return 0;

        if(dp[index][prev+1] != -1) return dp[index][prev+1];

        int maxi = 0;

        if(prev == -1 || nums[prev] <= nums[index]){
            maxi = max(maxi, 1 + lis(nums, index, index+1, dp));
        }

        maxi = max(maxi, lis(nums, prev, index+1, dp));

        return dp[index][prev+1] = maxi;
    }
public:
    bool checkPossibility(vector<int>& nums) {

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        
        int val = lis(nums, -1, 0, dp);
        cout << val << endl;

        if(val >= nums.size()-1) return true;
        else return false;
    }
};




// https://leetcode.com/problems/non-decreasing-array/solutions/106826/java-c-simple-greedy-like-solution-with-explanation/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1;
    }
};
