lass Solution{
public:

    int abso(int n)
    {
        return n <0? -n : n;
    }
    int *findTwoElement(int *arr, int n) {
        // code here
        
    //     long long sum = 0;
    //     for(int i=0;i<n;i++) sum += arr[i];
    //     long long reqSum = (n * (n+1))/2;
        
    //     long long diff = reqSum - sum;
        
        
    //     // need to find the dup number
    //     int index=-1,duplicate = -1;
    //   for(int i=0;i<n;i++)
    //     {
    //         index = abso(arr[i])-1;
            
    //         if(arr[index] < 0) 
    //         {
    //             duplicate = index+1;
    //             break;
    //         }
    //         arr[index] = -arr[index];
    //     }
        
    //     int missingNum = duplicate + diff;
        
    //     int a[2]  = {duplicate, missingNum};
    //     return a;
    
        
        
        int i,size=n;
       // cout << " The repeating element is ";
       
       int a[2];
    
        for (i = 0; i < size; i++) {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            else
                // cout << abs(arr[i]) << "\n";
                a[0] = abs(arr[i]);
        }
    
        //cout << "and the missing element is ";
        for (i = 0; i < size; i++) {
            if (arr[i] > 0)
                // cout << (i + 1);
                a[1] = i+1;
        }
        
        return a;
    }
};

// solution: https://leetcode.com/problems/find-the-duplicate-number/solution/
// question: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/