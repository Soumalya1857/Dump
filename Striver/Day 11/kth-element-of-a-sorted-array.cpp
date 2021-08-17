class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0,ans=0;
        while(i<n && j<m)
        {
            if(arr1[i] >= arr2[j]) ans = arr2[j++];
            else ans = arr1[i++];
            if(k==1) return ans;
            k--;
        }
        
        if(i==n) ans = arr2[j+k-1];
        else ans = arr1[i+k-1];
        return ans;
    }
};
// prb: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
// this is a linear solution. Worst solutions are obviously possible
// O(log(min(n,m))) approach and constant space
  class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // whats the min no of element from first arr => 1
        // whats the max element we can pick from an arr => min(k,len)
        // other array has k-num from it
        
        
        // int i=0,j=0,noFromFirst=0,noFromSecond=k-noFromFirst;
        // // can we do binary search
        // // lets try linear first
        
        // while(true)
        // {
        //     // check validity
        //     if(noFromFirst > 0)
        //     {
        //         int l1 = arr1[noFromFirst-1];
        //         int r1 = arr1[noFromFirst]; // possible r1 not exist
                
        //         int l2 = arr2[noFromSecond-1];
        //         int r2 = arr2[noFromSecond]; // also possible not exist
                
        //         if(l1 <= r2 && l2 <=r1)
        //         {
        //             // then valid state
        //             return max(l1,l2);
        //         }
        //         else if(l1 > r2)
        //         {
        //             noFromFirst++;
        //             noFromSecond = k-noFromFirst;
        //         }
        //         else if(l2 > r1)
        //         {
        //             noFromFirst--;
        //             noFromSecond = k-noFromFirst;
        //         }
        //     }
        // }
        
        if(n > m)
        {
            return kthElement(arr2, arr1, m,n,k); // very good thing this is
        }
        
        
        // now arr1 is smaller array in length than arr2
        int low = max(0,k-m), high=min(n,k); // how many min of max element we can take from arr1
        
        while(low <= high)
        {
            int cut1 = (low+high) >> 1;
            int cut2 = k-cut1;
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            if(l1 <= r2 && l2 <=r1) return max(l1,l2);
            else if(l1 > r2) high = cut1-1;
            else {
                low = cut1+1;
            }
        }
        
        // this will never executed
        return -1;
        
    }
};
// prb: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
// https://www.youtube.com/watch?v=nv7F4PiLUzo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=67