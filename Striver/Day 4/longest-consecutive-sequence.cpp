// o(nlogn) solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // map cannot be used as the time complexity for insertion is logN
        
        // sorting techinique 0(nlogn)
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        sort(nums.begin(),nums.end());
        int maxRange = INT_MIN,prevRange=1, currRange = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1] + 1) 
            {
                currRange = prevRange + 1;
                prevRange = currRange;
            }
            else if(nums[i] == nums[i-1]) {}// continue
            else
            {
                prevRange = 1;
                currRange = 1;
            }
            
            maxRange = max(maxRange,currRange);
        }
        
        return maxRange;
    }
};

// https://leetcode.com/problems/longest-consecutive-sequence/submissions/
// https://www.youtube.com/watch?v=qgizvmgeyUM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=22

// intuition is add all the number to the map
// then iterate over arr, checking if the prev number exists or not
// if doesn't => means thats the potential start of the sequence
// then check the streak by increasing the number and checking if it exists or not

// o(n) java solution
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> num_set = new HashSet<Integer>();
        for (int num : nums) {
            num_set.add(num);
        }

        int longestStreak = 0;

        for (int num : num_set) {
            if (!num_set.contains(num-1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.contains(currentNum+1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}