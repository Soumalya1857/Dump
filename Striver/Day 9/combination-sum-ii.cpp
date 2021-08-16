class Solution {
public:
    
    void getAllCombinations(vector<int>&candidates, int index, int target, vector<int> curr, vector<vector<int>>& ans)
    {
        //if(index == candidates.size()) return; // this is not needed as we are loosing some ans here
        if(target < 0) return;
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }
        
        // getAllCombinations(candidates, index+1, target, curr, ans); // not including recent index and going to next index
        // curr.push_back(candidates[index]);
        // getAllCombinations(candidates,index+1,target-candidates[index],curr,ans);
        
        
        for(int i=index;i<candidates.size();i++)
        {
            if(i != index && candidates[i] == candidates[i-1]) continue;
            
            //getAllCombinations(candidates, i+1, target, curr, ans); this is not necessary as we already adding all the unique elements after index to arr with help of the for loop
            curr.push_back(candidates[i]);
            getAllCombinations(candidates, i+1, target-candidates[i], curr, ans);
            curr.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        getAllCombinations(candidates,0, target,curr, ans);
        return ans;
    }
};

// peb: https://leetcode.com/problems/combination-sum-ii/submissions/
// soln: https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=51