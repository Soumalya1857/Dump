// need to find no of subarr such that ith element in the arr is the min of that subarr


#include<bits/stdc++.h>
using namespace std;

int returnSubarr(vector<int> &arr, int index)
{
    int n = arr.size();
    int left = 0;
    int right = n;
    int i = index+1;
    int j = index-1;

    
    while(arr[index] < arr[i] && i<n)
    {
        right = i;
        i++;
    }
    while(arr[index] < arr[j] && j>=0)
    {
        left = j;
        j--;
    }

    int count = (index-j)*(right - index);
    count++;

    return count;    
}
