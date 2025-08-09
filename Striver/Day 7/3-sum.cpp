class Solution {
public:
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // sort kore two pointer method
        
//         vector<vector<int>> ans;
//         int size = nums.size();
//         sort(nums.begin(), nums.end());
        
//         for(int i=0;i<size-1;i++)
//         {
//             if(i>0 && nums[i] == nums[i-1]) continue;
//             else
//             {
//                 int start = i+1, end=size-1;
//                 int target = 0-nums[i];
//                 while(start < end)
//                 {
//                     cout << "curr: " << nums[i] << " start: " << nums[start] << " end: " << nums[end] << endl;
//                     if(nums[start] + nums[end] > target) end--;
//                     else if(nums[start] + nums[end] < target) start++;
//                     else
//                     {
//                         ans.push_back(vector<int>{nums[i], nums[start], nums[end]});
//                         ++start;
//                         while(start<end && nums[start] == nums[start-1]) ++start;
//                     }
//                 }
//             }
            
//         }
        
//         return ans;
        
        
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        //vector<vector<int>> :: iterator it;
        map<vector<int>, bool> m;
        for(int i=0; i< nums.size(); i++)
        {
            int curr = nums[i];
            int low = i+1;
            int high = n-1;
            while(low < high)
            {
                if(curr + nums[low] + nums[high] == 0)
                {
                    vector<int> temp = {curr, nums[low], nums[high]};
                    // it = find(ans.begin(), ans.end(), temp);
                    // if(it == ans.end())
                    //     ans.push_back(temp);
                    if(m[temp] == false) {
                        ans.push_back(temp);
                        m[temp] = true;
                    }
                    low++;
                }
                else if(curr + nums[low] + nums[high] > 0)
                {
                    high--;
                }
                else if(curr + nums[low] + nums[high] < 0)
                {
                    low++;
                }
            }
            
        }
        return ans;
    }
};

// prob: https://leetcode.com/problems/3sum/
// soln:https://www.youtube.com/watch?v=onLoX6Nhvmg&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=41