class Solution {

    private int get(int[] nums, int index){
        int size = nums.length;
        if(index < 0 || index >= size) return Integer.MIN_VALUE;
        return nums[index];
    }

    public int findPeakElement(int[] nums) {
        // binary search
        // if an element i, i-1 < i < i + 1 => peak element on the right
        // if an element i-1 > i > i + 1 => peak element on the left


        int size = nums.length;
        int low = 0, high = size-1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(get(nums, mid-1) <= get(nums, mid) && get(nums, mid) >= get(nums, mid+1)) { // mid is peak element
                return mid;
            } else if(get(nums, mid-1) <= get(nums, mid) && get(nums, mid) <= get(nums, mid+1)) { // peak on the right of mid
                low = mid+1;
            } else {
                high = mid-1; // peak on left
            }
        }

        return -1;
    }
}

// https://leetcode.com/problems/find-peak-element/submissions/1954818150/