class Solution {
public:
    
    int merge(vector<long long int>&nums, vector<long long int>&temp,int left, int mid, int right)
    {
        int i=left, j=mid, k=left;
        int reverse = 0;
        
        // here we need to implement the reverse counting algo
        for(i=left;i<mid;i++)
        {
            while(j <= right && (nums[i] > 2*nums[j]))
            {
                j++;
            }
            
            reverse += (j-mid); // when we got the first j for which the condition doesn't holds we can say for all prev j that condition holds
        }
        
        i=left,j=mid,k=left;
        while((i<=mid-1) && (j <=right))
        {
            if(nums[i] > nums[j]){
                temp[k++] = nums[j++];
            }
            else
                temp[k++] = nums[i++];
        }
        // we have to do this steps as we are modifying the steps
        
        while(i<=mid-1) temp[k++] = nums[i++];
        while(j <= right) temp[k++] = nums[j++];
        for(i=left;i<=right;i++) nums[i] = temp[i];
        return reverse;
    }
    int mergeSort(vector<long long int>&nums, vector<long long int>&temp, int left, int right)
    {
        int reverse = 0;
        if(left<right)
        {
            int mid =(left+right)/2;
            reverse += mergeSort(nums,temp,left,mid);
            reverse += mergeSort(nums,temp,mid+1,right);
            
            reverse += merge(nums,temp,left,mid+1,right); // mid+1 as thats the starting point of 2nd array
        }
        return reverse;
    }
    int reversePairs(vector<int>& nums) {
        // exactly same as count inversion
        
        // merge sort lagao
        
        int size = nums.size();
        vector<long long int> myNums;
        myNums.assign(nums.begin(), nums.end());
        vector<long long int> temp(size);
        
        int ans = mergeSort(myNums, temp, 0, size-1);
        return ans;
    }
};

// soln: https://leetcode.com/problems/reverse-pairs
// ans: https://www.youtube.com/watch?v=S6rsAlj_iB4&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18
