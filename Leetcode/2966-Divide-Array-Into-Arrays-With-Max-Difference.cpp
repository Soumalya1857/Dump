class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0, size = nums.size();

        vector<vector<int>> result;
        bool isPossible = true;

        while(start < size){
            if(nums[start+2] - nums[start] > k){
                isPossible = false;
                break;
            }

            result.push_back({nums[start], nums[start+1], nums[start+2]});

            start = start+3;
        }


        return isPossible == true ? result : vector<vector<int>> ();
    }
};

// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/

// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/
// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/solutions/4656943/counting-sort-with-time-onm-vs-sort-1-liner74ms-beats-100/

// Bad solution nlog(n)