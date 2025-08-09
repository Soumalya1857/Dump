/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int getValue(MountainArray &m, vector<int> &arr, int index, int size){
        if(index < 0 || index >= size) return -1;
        if(arr[index] != -1){
            return arr[index];
        }

        return arr[index] = m.get(index);
    }

    int binarySearch(MountainArray &m, vector<int> &arr, int low, int high, int target, int size){

        int result = -1;

        while(low < high){
            int mid = (low+high)/2;

            int curr = getValue(m,arr,mid,size);

            if(curr == target) {
                result = mid;
                int betterPossible = binarySearch(m,arr,low,mid-1, target, size);
                return betterPossible != -1 ? betterPossible : result;
            }

            int left = getValue(m,arr,mid-1,size);
            int right = getValue(m,arr,mid+1, size);

            if(left < curr && curr < right){
                if(target > curr){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            } else if(left > curr && curr > right){
                if(target > curr){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else { // mid is the inflextion point
                int leftIndex = binarySearch(m,arr,low,mid,target,size);
                int rightIndex = binarySearch(m,arr,mid+1, high, target, size);

                if(leftIndex != -1 && getValue(m,arr,leftIndex,size) == target) return leftIndex;
                if(rightIndex != -1 && getValue(m,arr,rightIndex,size) == target) return rightIndex;

                return -1;
            }
        }


        if(getValue(m,arr,low,size) == target) return low;

        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int size = mountainArr.length();
        if(size < 3) return -1;

        vector<int> arr(size, -1);

        int low = 0, high = size-1;

        return binarySearch(mountainArr,arr,0,size-1,target,size);


    }
};

// https://leetcode.com/problems/find-in-mountain-array/



// better solution => find the peak and then perform binary search on both ends
// https://leetcode.com/problems/find-in-mountain-array/solutions/4159000/100-binary-search-explained-intuition/
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();

        // Find the index of the peak element in the mountain array.
        int peakIndex = findPeakIndex(1, length - 2, mountainArr);

        // Binary search for the target in the increasing part of the mountain array.
        int increasingIndex = binarySearch(0, peakIndex, target, mountainArr, false);
        if (mountainArr.get(increasingIndex) == target)
            return increasingIndex; // Target found in the increasing part.

        // Binary search for the target in the decreasing part of the mountain array.
        int decreasingIndex = binarySearch(peakIndex + 1, length - 1, target, mountainArr, true);
        if (mountainArr.get(decreasingIndex) == target)
            return decreasingIndex; // Target found in the decreasing part.

        return -1;  // Target not found in the mountain array.
    }

    int findPeakIndex(int low, int high, MountainArray &mountainArr) {
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1; // Move to the right side (increasing slope).
            } else {
                high = mid; // Move to the left side (decreasing slope).
            }
        }
        return low; // Return the index of the peak element.
    }

    int binarySearch(int low, int high, int target, MountainArray &mountainArr, bool reversed) {
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (reversed) {
                if (mountainArr.get(mid) > target)
                    low = mid + 1; // Move to the right side for a decreasing slope.
                else
                    high = mid; // Move to the left side for an increasing slope.
            } else {
                if (mountainArr.get(mid) < target)
                    low = mid + 1; // Move to the right side for an increasing slope.
                else
                    high = mid; // Move to the left side for a decreasing slope.
            }
        }
        return low; // Return the index where the target should be or would be inserted.
    }
};