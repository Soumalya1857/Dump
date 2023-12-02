class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> map;
        for(int i=0; i< nums.size(); i++){
            map[nums[i]].push_back(i);
        }
        vector<int> dp(nums.size()+1, -1);
        return solve(nums,map,dp,0);
    }

    int solve(vector<int> nums, unordered_map<int, vector<int>> &map, vector<int> &dp, int currIndex){
        if(currIndex >= nums.size()){
            return 0;
        }

        if(dp[currIndex] != -1) 
            return dp[currIndex];

        int localAns1 = 0, localAns2 = 0;

        // we can choose not to take the element
        if(dp[currIndex+1] != -1){
            localAns1 = dp[currIndex+1];
        }
        else{
            localAns1 = solve(nums, map, dp, currIndex+1);
        }
        
        // or we can take the element
        if(nums[currIndex] > 0){
            localAns2 = nums[currIndex];
            for(int index : map[nums[currIndex]-1]){
                if(nums[index] > 0) 
                    nums[index] *= -1;
            }

            for(int index : map[nums[currIndex]+1]){
                if(nums[index] > 0) 
                    nums[index] *= -1;
            }

            if(dp[currIndex+1] != -1){
                localAns2 += dp[currIndex+1];
            }
            else{
                localAns2 += solve(nums, map, dp, currIndex+1);
            }
            //localAns2 += solve(nums, map, dp, currIndex+1);
        }

        return dp[currIndex] = max(localAns1, localAns2);
    }
};

// solution: https://leetcode.com/problems/delete-and-earn/solutions/1820279/c-detailed-explanation-w-recursion-to-memoziation-understand-concept/

// problem: https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int t[20001]; // declaring 1 d array, to store some already computed results
    int solve(vector<int> &arr, int i)
    {
        if(i >= arr.size()) // if i is greater than size of array
        {
            return 0; // then simply returnn zero
        }
        
         // if result is already computed, then return from here
        // this one line which we say to add
        if(t[i] != -1)
        {
            return t[i];
        }
        
        // current 'i' on which we are standing
        int currValue = arr[i];  // current value
        int currSum = arr[i]; // intial make sum as same as value
        int index = i + 1; // index to take elemets, so  i + 1
        
        // while it is the same as the current value, include in our sum
        while(index < arr.size() && arr[index] == currValue)
        {
            currSum += arr[i];
            index++;
        }
        
        // Now, we have to skip all the elements, whose value is equal to
        // currValue + 1
        while(index < arr.size() && arr[index] == currValue + 1)
        {
            index++;
        }
        
        //And lastly, we have two choices-
        //whether to include the sum of this current element in our answer
        // or not include the sum of current element in our answer
        // so we explore all possibility and take maximum of them
        
        return t[i] = max(currSum + solve(arr, index), solve(arr, i + 1));
        
        // If we decide to take the curr element in our answer, then upto the elemet we skip the next value, we paas that index
        // but if decided no to make this vurrent element then simply paas
        // i + 1
    }
    int deleteAndEarn(vector<int>& arr) {
        int n = arr.size(); // take the size of the array
        
        memset(t, -1, sizeof(t));
        
        // sort the array to get rid of all arr[i] - 1 elements
        sort(arr.begin(), arr.end());
        
        // solve function which give us our final answer
        return solve(arr, 0);
        //                ↑
        //                we start from zero index
    }
};


// this problem can be reduced to house robber 
// just try to reword the problem 
// great solution : https://leetcode.com/problems/delete-and-earn/solutions/109895/java-c-clean-code-with-explanation/

// solution: 
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};

/**
 * @brief 
 * If we sort all the numbers into buckets indexed by these numbers, this is essentially asking you to repetitively take an bucket while giving up the 2 buckets next to it. (the range of these numbers is [1, 10000])

The optimal final result can be derived by keep updating 2 variables skip_i, take_i, which stands for:
skip_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you skip the ith bucket.
take_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you take the ith bucket.

DP formula:
take[i] = skip[i-1] + values[i];
skip[i] = Math.max(skip[i-1], take[i-1]);
take[i] can only be derived from: if you skipped the [i-1]th bucket, and you take bucket[i].
skip[i] through, can be derived from either take[i-1] or skip[i-1], whatever the bigger; 
 * 
 */
