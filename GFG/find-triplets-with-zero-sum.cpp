class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {
        //Your code here
        sort(arr, arr+n);


        for(int i=0; i<n-2; i++){
            int target = 0 - arr[i];

            int start = i+1;
            int end = n-1;

            while(start < end){
                if(arr[start] + arr[end] > target){
                    end--;
                } else if(arr[start] + arr[end] < target){
                    start++;
                } else if(arr[start] + arr[end] == target){
                    return 1;
                }
            }
        }

        return 0;
    }
};

// https://www.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1?page=3&company=Google&sortBy=difficulty