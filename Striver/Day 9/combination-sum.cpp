class Solution {
public:
    
    
    void getAllCombinations(vector<int>&candidates, int index, int target, vector<int> curr, vector<vector<int>>& ans)
    {
        if(index == candidates.size()) return;
        if(target < 0) return;
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }
        
        //getAllCombinations(candidates, index+1, target, curr, ans);
        curr.push_back(candidates[index]);
        getAllCombinations(candidates, index, target-candidates[index], curr, ans); // this is where infinte idea comes in => pick the index here
        curr.pop_back();
        getAllCombinations(candidates, index+1, target, curr, ans); // not including recent index and going to next index
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        getAllCombinations(candidates,0, target,curr, ans);
        return ans;
    }
};
// prb: https://leetcode.com/problems/combination-sum/submissions/
// soln: https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=50


class Solution {
private:

    void solve(vector<int> &candidates, int index, int target, vector<int> combination, vector<vector<int>>&ans){
        if(target < 0){
            return;
        }

        if(target == 0){
            ans.push_back(combination);
            return;
        }

        if(index == candidates.size()){
            return;
        }


        // take the element and continue
        combination.push_back(candidates[index]);
        solve(candidates, index, target-candidates[index],combination, ans);

        combination.pop_back();
        // not take the element and proceed
        solve(candidates, index+1, target, combination, ans);
    }


public:


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;

        solve(candidates, 0, target, combination, ans);

        return ans;
    }
};