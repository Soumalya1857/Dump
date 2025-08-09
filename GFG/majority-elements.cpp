class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int majorityElement = -1;
        int count = 0;
        
        for(int i=0; i<size;i++){
            if(count == 0){
                count++;
                majorityElement = a[i];
            }
            else if(a[i] == majorityElement){
                count++;
            }else{
                count--;
            }
        }
        
        // now check if the element is actually a majority element
        count = 0;
        for(int i=0; i<size; i++){
            if(a[i] == majorityElement){
                count++;
            }
        }
        
        if(count > size/2) return majorityElement;
        else return -1;
    }
    
    // https://www.geeksforgeeks.org/problems/majority-element-1587115620/1?page=2&company=Google&sortBy=difficulty
};