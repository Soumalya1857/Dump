// check number of good sequence

// good sequence => a[i] == a[i+1] or a[i] == a[i+1]-1

// 7 4 5 6 5

// 7 , 4, 5, 6, 5, 4 5, 4 5 6, 5 6, 6 5

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

        int numberOfGoodSequences(vector<int> &nums){

            int len = 0;
            int end = 0;
            bool isIncreasingSq = false;
            bool isDecresingSq = false;

            int result = 0;

            //

            while(end < nums.size()-1){

                if(isIncreasingSq == true){
                    if(nums[end]+1 == nums[end+1]){
                        end++;
                        len++;
                        continue;
                    }else{ // end of incresing sq
                         isIncreasingSq = false;
                         result += (len*(len+1))/2 - len;

                         len = 1;
                         //end++;
                     }
                } else if(isDecresingSq == true){
                    if(nums[end]-1 == nums[end+1]){
                        end++;
                        len++;
                    }else{ // end of decreasing sq
                        isDecresingSq = false;
                        result += (len * (len+1))/2;

                        len = 1;
                        //end++;
                    }
                } else{ // both values are false
                    if(nums[end]+1 == nums[end+1]){ // 4 5 6e 3
                        isIncreasingSq = true;
                    } else if(nums[end] -1 == nums[end]){
                        isDecresingSq = true;
                    } else{
                        end++;
                        len = 1;
                    }

                }
            }

            // last one
            cout << len << endl;
            result += (len * (len+1))/2 - len;

            return result + nums.size();

        }

};


int main(){

    vector<int> nums{7,4,5,6,5};
    Solution sol;

    cout << sol.numberOfGoodSequences(nums) << endl;
    return 0;
}