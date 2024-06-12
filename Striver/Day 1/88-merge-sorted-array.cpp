// https://leetcode.com/problems/merge-sorted-array/description/
// youtube: https://www.youtube.com/watch?v=n7uwj04E0I4&t=0s


class Solution{

    public:
        void mergeSortedArr(vector<int>& arr1, vector<int>& arr2){
            int left = arr1.size()-1, right = 0; // one place on last index, one on first of 2nd arr

            while(left>=0 && right<arr2.size()){
                if(arr1[left] > arr2[right]){
                    swap(arr1[left], arr2[right]);
                    left--;
                    right++;
                }else{
                    break; // as the arrays are sorted, no need to check again
                }
            }

            sort(arr1.begin(), arr1.end());
            sort(arr2.begin(), arr2.end());
        }
};