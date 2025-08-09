class Solution {
public:
    int maximumXOR(vector<int>& nums) {
//         int ans = 0;
//         for(int bit=0;  bit<32; bit++){
//             int count1 = 0;
//             for(int i=0; i<nums.size(); i++){
//                 if(nums[i] & (1<< bit)) count1++;
//             }
//             // cout << "bit: " << bit << " count1: " << count1 << endl;
//             if(count1 > 0) ans += (1 << bit);
//         }
        
//         return ans;
        
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            ans=ans|nums[i];
        }
        return ans;
    }
    
};
// https://leetcode.com/problems/maximum-xor-after-operations/


// another solution
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;

        for(int bit=31; bit>=0; bit--){

            for(int j=0; j<nums.size(); j++){
                if(nums[j] & (1<<bit)){
                    ans = ans | (1<<bit);
                    break;
                }
            }
        }

        return ans;
    }
};