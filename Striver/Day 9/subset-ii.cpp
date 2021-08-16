class Solution {
public:
    
    void getPowerSet(vector<int> &nums, int pos, vector<int> curr, set<vector<int>> &dupCheck, vector<vector<int>> &ans)
    {
        if(pos == nums.size())
        {   
           
            if(dupCheck.find(curr) == dupCheck.end())
            {
                dupCheck.insert(curr);
                ans.push_back(curr);
            }
                 
            return;
        }
        getPowerSet(nums, pos+1, curr, dupCheck,ans);
        curr.push_back(nums[pos]);
        getPowerSet(nums, pos+1, curr, dupCheck, ans);
         
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>subset;
        set<vector<int>> dupCheck;
         sort(nums.begin(),nums.end());
        getPowerSet(nums,0, subset, dupCheck, ans);
        return ans;
    }
};

// prb: https://leetcode.com/problems/subsets-ii/submissions/
// soln: https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=54


// better approach
class Solution {
public:
    
    void getPowerSet(vector<int> &nums, int index, vector<int> curr, vector<vector<int>> &ans)
    {
        
//         if(index == nums.size())
//         {
//             return;
//         }
        
//         curr.push_back(nums[index]);
//         ans.push_back(curr);
//         getPowerSet(nums, index+1, curr, ans);
//         curr.pop_back();
        
//         for(int i=index+1; i<nums.size(); i++)
//         {
//             if(nums[i] == nums[i-1]) ++i;
//             else
//             {
//                 curr.push_back(nums[i]);
//                 //ans.push_back(curr);
//                 getPowerSet(nums,i+1,curr, ans);
//                 curr.pop_back();
//             }
        
            ans.push_back(vector<int>(curr));
            for(int i=index;i<nums.size();i++)
            {
                if(i != index  && nums[i] == nums[i-1]) continue; // forces to execute next iteration of the loop
                curr.push_back(nums[i]);
                getPowerSet(nums, i+1, curr, ans); // i+1 bec we should iterate from the i+1th index next tiime on 
                curr.pop_back();    // pop back to make sure we are maintaining the state of curr and not passing extra element on next recursion stages
            }
        }
        
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // retest with strivers method
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        // so we will do this thing
        // we will maintain an index for which we wll start putting value into a data structure
        // and also will check the value we are putting is not duplicate one
        
        vector<int> curr;
        getPowerSet(nums,0,curr, ans);
        return ans;
        
    }
};

// solution: https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=54