//User function template in C++
class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isAllocationPossible(int arr[], int n, int m, int bar)
    {
        int student = 1, curr=0;
        for(int i=0;i<n;i++)
        {
            if(bar < arr[i]) return false; // cannot allocate a whole book if bar is smaller than a book itself
            curr += arr[i];
            if(curr > bar)
            {
                //i--; // remove that book from this guy and gave it to another guy
                student++; // i will need one extra student to allocate
                curr = arr[i];  // reset curr to calculate for next guy
            }
        }
        
        return student > m ? false : true;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m > n) return -1;
        int res = INT_MIN;
        int minRange = *min_element(arr, arr+n);
        int maxRange = 0;
        for(int i=0;i<n;i++) maxRange += arr[i]; // maxRange would be the sum of all elements
        
        int low = minRange, high = maxRange;
        while(low <= high)
        {
            int mid = (low+high) >> 1;
            if(isAllocationPossible(arr,n,m,mid))
            {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return low; // when high crosses the low => low will be the first number from where we can start allocating
    }
};
// prb: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// sol: https://www.youtube.com/watch?v=wSOfYesTBRk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=70