// normal solution

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if(n==0) return 0;
//         if(n==1) return 1;
        
        
//         vector<int> lis(n,1);
//         int ans = -1;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(nums[i] > nums[j])
//                     if(lis[i] < lis[j] + 1)
//                         lis[i] = lis[j]+1;
//             }
//             ans = max(ans,lis[i]);
//         }
        
//         return ans;
//     }
// };


// Binary search

/*
in this approach, we scan the array from left to right. 
We also make use of a dpdp array initialized with all 0's. 
This dpdp array is meant to store the increasing subsequence formed by including the currently encountered element.
 While traversing the numsnums array, we keep on filling the dpdp array with the elements encountered so far. 
 For the element corresponding to the j^{th}j 
i th
  index (nums[j]nums[j]), we determine its correct position in the dpdp array(say i^{th}i 
th
  index) by making use of Binary Search(which can be used since the dpdp array is storing increasing subsequence) and also insert it at the correct position. An important point to be noted is that for Binary Search, we consider only that portion of the dpdp array in which we have made the updates by inserting some elements at their correct positions(which remains always sorted). Thus, only the elements upto the i^{th}i 
th
  index in the dpdp array can determine the position of the current element in it. Since, the element enters its correct position(ii) in an ascending order in the dpdp array, the subsequence formed so far in it is surely an increasing subsequence. Whenever this position index ii becomes equal to the length of the LIS formed so far(lenlen), it means, we need to update the lenlen as len = len + 1len=len+1.

Note: dpdp array does not result in longest increasing subsequence, but length of dpdp array will give you length of LIS
*/

public class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int len = 0;
        for (int num : nums) {
            int i = Arrays.binarySearch(dp, 0, len, num);
            if (i < 0) {
                i = -(i + 1);
            }
            dp[i] = num;
            if (i == len) {
                len++;
            }
        }
        return len;
    }
}