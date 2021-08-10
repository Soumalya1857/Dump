// class Solution {
// public:
    
//     vector<vector<int>> twoSum(vector<int>&nums, int left, int right, int target)
//     {
//         unordered_map<int,int> mp;
//         vector<vector<int>> twoSumIndex;
//         for(int i=left; i<=right;i++)
//         {
//             if(mp.find(target-nums[i]) != mp.end())
//             {
//                 int index = mp[target-nums[i]];
//                 twoSumIndex.push_back(vector<int>{nums[i],nums[index]});
//             }
            
//             mp.insert(make_pair(nums[i],i));
//         }
        
//         return twoSumIndex;
//     }
    
//     vector<vector<int>> threeSum(vector<int>&nums, int left, int right, int target)
//     {
//         vector<vector<int>> threeSumIndex;
//         for(int i=left; i<=right; i++)
//         {
//             int curr = nums[i];
//             int complement = target-curr;
            
//             vector<vector<int>> twoSumIndex = twoSum(nums,i+1,right,complement);
//             for(auto x : twoSumIndex)
//             {
//                 x.push_back(curr);
//                 threeSumIndex.push_back(x);
//             }
//         }
        
//         return threeSumIndex;
//     }
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         // all unique quadriplates
//         vector<vector<int>> fourSumIndex;
//         int size = nums.size();
        
//         for(int i=0;i<size;i++)
//         {
//             int curr = nums[i];
//             int complement = target - complement;
            
//             vector<vector<int>> threeSumIndex = threeSum(nums,i+1,size-1,complement);
//             //cout<< "threeSum for i= " << i << "\n" ;
//             for(auto x : threeSumIndex)
//             {
//                 //for(auto p: x) cout << p << " ";
//                // cout << endl;
//                 x.push_back(curr);
//                 fourSumIndex.push_back(x);
//             }
            
//         }
        
//         return fourSumIndex;
        
//     }
    
// };

// /*
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     sort(begin(nums), end(nums));
//     return kSum(nums, target, 0, 4);
// }
// vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
//     vector<vector<int>> res;
//     if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
//         return res;
//     if (k == 2)
//         return twoSum(nums, target, start);
//     for (int i = start; i < nums.size(); ++i)
//         if (i == start || nums[i - 1] != nums[i])
//             for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
//                 res.push_back({nums[i]});
//                 res.back().insert(end(res.back()), begin(set), end(set));
//             }
//     return res;
// }
// vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
//     vector<vector<int>> res;
//     unordered_set<int> s;
//     for (auto i = start; i < nums.size(); ++i) {
//         if (res.empty() || res.back()[1] != nums[i])
//             if (s.count(target - nums[i]))
//                 res.push_back({ target - nums[i], nums[i]});
//         s.insert(nums[i]);
//     }
//     return res;
// }
// };
// */



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i,j,n=nums.size(),remain,low,high,twoSum;
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        sort(nums.begin(), nums.end());
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                remain=target-nums[i]-nums[j];
                low=j+1, high=n-1;
                while(low<high){
                    twoSum=nums[low]+nums[high];
                    if(twoSum<remain) low++;
                    else if(twoSum>remain) high--;
                    else{
                        vector<int> temp(4,0);
                        temp[0]=nums[i]; temp[1]=nums[j];
                        temp[2]=nums[low]; temp[3]=nums[high];
                        ans.push_back(temp);
                        //Processing the number for duplicate 3
                        while(low<high && nums[low]==temp[2]) low++;
                        //Processing the number for duplicate 4
                        while(low<high && nums[high]==temp[3]) high--;
                    }
                }
                //Processing the number for duplicate 2
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            //Processing the number for duplicate 1
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
};

// https://leetcode.com/problems/4sum/discuss/1386342/C%2B%2B-or-Two-Pinter-with-for-loop-%2B-Sort
// prb: https://leetcode.com/problems/4sum/