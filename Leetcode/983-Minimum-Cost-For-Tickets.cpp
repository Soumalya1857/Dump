class Solution {

private:
    int getIndex(vector<int> &days, int index, int val){
        int target = days[index] + val -1;

        // i want to find the next greater element

        int low = index, high = days.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(days[mid] == target) return mid+1;
            else if(days[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return low; // always greater
    }

    int solve(vector<int> &days, vector<int> &costs, int index, vector<int> &dp){
        if(index >= days.size()){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int mini = INT_MAX;

        // 1 day pass
        mini = min(mini, costs[0] + solve(days, costs, index+1, dp));

        // 7days pass
        int newIndex = getIndex(days, index, 7);
        mini = min(mini, costs[1] + solve(days, costs, newIndex, dp));

        // 30day pass
        newIndex = getIndex(days, index, 30);
        mini = min(mini, costs[2] + solve(days, costs, newIndex, dp));

        return dp[index] = mini;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(days, costs, 0, dp);
    }
};

// https://leetcode.com/problems/minimum-cost-for-tickets/submissions/1539701060/