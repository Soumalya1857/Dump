class Solution {
  public:
    int search(int arr[], int l, int h, int key) {
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        // complete the function here

        while(l<h){
            int mid = (l+h)/2;
            if(arr[mid] == key) return mid;

            if(arr[mid] > arr[h]){
                if(arr[mid] < key){
                    l = mid+1;
                }
                else if(arr[mid] > key){

                    if(key > arr[h]){
                        h = mid-1;
                    } else if(key <= arr[h]){
                        l = mid+1;
                    }
                }else{
                    return mid;
                }
            }

            else if(arr[mid] <= arr[h]){
                if(key < arr[mid]){
                    h = mid-1;
                } else if(key > arr[mid]){

                    if(key > arr[h]){
                        h = mid-1;
                    }
                    else if(key <= arr[h]){
                        l = mid+1;
                    }
                } else{
                    return mid;
                }
            }
        }

        if(arr[l] == key) return l;

        return -1;
    }

    // https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1?page=3&company=Google&sortBy=difficulty
};