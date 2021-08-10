// from striver but TLE dicche 
// will try another solution


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
   long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
   {
       // need to find inversion count over here
       
       long long inv_count = 0, i = left,j=mid,k=left;
        // i is index for left subarray, j is index for right subarray, k is index for resultant merged subarray
        
        while(i<=mid-1 && j<=right)
        {
            if(arr[i] <= arr[j]) temp[k++] = arr[i++];
            else {
                // add to temp and also add to inv_count the size of the first array remaining
                temp[k++] = arr[j++];
                inv_count += (mid-i);
            }
        }
        
        // add the remaining bits
        while(i<=mid-1)
        {
            temp[k++] = arr[i++];
        }
        
        while(j<=right) temp[k++] = arr[j++];
        for(i=left; i<=right;i++) arr[i] = temp[i];
        return inv_count;
   }
  
  
  
    long long mergeSort(long long arr[], long long temp[], long long left, long long right)
    {
        // do mergeSort over here
        long long mid,inv_count = 0;
        if(left < right)
        {
            mid = (left+right)/2;
            
            inv_count += mergeSort(arr,temp,left,mid);
            inv_count += mergeSort(arr,temp,mid+1,right);
            
            inv_count += merge(arr, temp, left, mid+1, right);
        }
        
        return inv_count;
    }
  
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        // number of elements lesser than it to its left
        
        // there is a complex binary tree approach for this 
        // not at all intuitive
        
        // fenwick tree FFFFFF
        // there is a merge sort technique to it
        // the idea is while merging we will count the swaps needed that will be our desired number of inversions
        
        
        long long temp[N];
        long long ans = mergeSort(arr, temp, 0, N-1);
        return ans;
        
    }

};


// prblem: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
// similar leetcode: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// https://www.youtube.com/watch?v=kQ1mJlwW-c0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12






// this code is from gfg
// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);

/* This function sorts the
   input array and returns the
number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function
  that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Driver code
int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}

// This is code is contributed by rathbhupendra