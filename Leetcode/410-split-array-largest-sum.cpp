class Solution {

private:
    bool isPartitionPossible(vector<int> &nums, int k, int sum){
        int currSum = 0;
        int partition = 0;

        for(int i=0; i<nums.size(); i++){
            if(currSum + nums[i] > sum){
                partition++;
                currSum = nums[i];
            }else{
                currSum += nums[i];
            }
        }

        partition++;

        return partition <= k ? true : false;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int maxi=0, sum=0;

        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            sum += nums[i];
        }

        int result = -1;

        int low = maxi, high = sum;
        while(low <= high){
            int mid = (low + high)/2;

            if(isPartitionPossible(nums, k, mid)){
                result = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/split-array-largest-sum/
// https://www.youtube.com/watch?v=YUF3_eBdzsk