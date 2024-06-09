class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        unordered_map<int,int> mp;

        int count = 0;

        for(int i: nums1){
            for(int j: nums2){
                mp[i+j]++;
            }
        }

        for(int i: nums3){
            for(int j: nums4){
                if(mp[-(i+j)] != 0){
                    count += mp[-(i+j)];
                }
            }
        }

        return count;
    }
};

// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/829/
// https://leetcode.com/problems/4sum-ii/solutions/1740606/going-from-o-n-4-o-n-3-o-n-2-java-c/