class Solution {
  public:

  // https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1?page=6&company=Google&sortBy=difficulty

  bool isAllocationPossible(int arr[], int N, int K, int currMaxSum){
      int runningSum = 0, partitionCount = 1;

      for(int i=0; i<N; i++){
          if(runningSum + arr[i] > currMaxSum){
              partitionCount++;
              runningSum = arr[i];
          } else if(runningSum + arr[i] <= currMaxSum){
              runningSum += arr[i];
          }
      }

      if(partitionCount <= K) return true;
      else return false;

  }

    int splitArray(int arr[] ,int N, int K) {
        // code here
        int sum = 0, maxi = 0;
        for(int i=0; i<N; i++){
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }

        if(K >= N) return maxi;

        // binary search between high and low
        int low = maxi, high = sum, result = -1;
        while(low <= high){
            int mid = (low + high)/2;
            // cout <<"before: " <<  low << " " <<  high << " " << mid << " " << endl;

            if(isAllocationPossible(arr, N, K, mid)){
                result = mid; // if partition is possible for a given sum we will check if any lower number is possbile or not
                high = mid-1;
            }else{
                low =  mid + 1;
            }

            // cout << "after: " << low << " " << high << endl;
        }

        return result;

    }
};