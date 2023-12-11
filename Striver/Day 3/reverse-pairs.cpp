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



// normal merge sort == nothing to do with it

// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
