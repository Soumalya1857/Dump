class Solution {
public:
    
    void myReverse(vector<int>&nums, int i, int j)
    {
        // reverses i to jth part in nums arr
        while(i < j) swap(nums,i++,j--);
    }
    void nextPermutation(vector<int>& nums) {
        
        // whats the intuition
        // backside theke ekta increasing sequece hoy
        // detect the sequencce and find the break point
        
        // oi particular point take increase korte hobe to increase the rank
        
        // ekhon increase korbo with the smallest larger number to that point (from its right)
        
        // swap with that number
        // and now try to minimize the rank by reversing all the number to the right of that break point
        
        
        
        
        if(nums.size() == 0) return;
        
        int len = nums.size(), i,j,k;
        bool isLast = true;
        for(i=len-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1]) {isLast = false; break;}
        }
        
        // now i contains the breakpoint index
        // but one case can be if the permutation is already the last permutation
        if(isLast) reverse(nums.begin(), nums.end());
        else
        {
            // find just large element to i's right
        
            for(j=len-1;j>i;j--){
                if(nums[j] > nums[i]) break;
            }

            // now j contains the just large element

            // swap ith and jth pos
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            reverse(nums.begin()+i+1, nums.end());
        }
    }
};

// prob: https://leetcode.com/problems/next-permutation/
// best solution: https://www.youtube.com/watch?v=LuLCLgMElus&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=10

// Great video: https://www.youtube.com/watch?v=JDOXKqF60RQ&t=0s



class Solution {
public:

	// step1; find a break point from last
		// strp2: the number in increasing zone just greater than breakpoint
		// swap the numbers
// sort/ reverse the array after the swapping point

  void nextPermutation(vector<int> &arr){

	int n = arr.size();

	int index = -1;
	for(int i=n-2; i>=0; i--){
		if(arr[i] < arr[i+1]){
			index = i;
			break;
}
}

if(index == -1){
	reverse(arr.begin(), arr.end());
	return;
}


for(int i=n-1; i>=0; i--){
	if(arr[index] < arr[i]){
		swap(arr[index], arr[i]);
		break;
}
}

reverse(arr.begin()+index+1, arr.end());
return;
}
};