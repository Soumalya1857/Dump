class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp; // val, index

        vector<int> prefix(nums.size());
        prefix[0] = nums[0]%k;

        for(int i=1; i<nums.size(); i++){

            prefix[i] = (prefix[i-1]%k + nums[i]%k)%k;

            if(prefix[i] % k == 0) return true;

            for(int j=0; j<i; j++){
                int sum = ((prefix[i] - prefix[j]))%k;
                if(sum % k == 0 && (i-j)>1){
                    return true;
                }
            }

           // mp[prefix[i]] = i;

        }

        return false;
    }
};

// TLE found: 94/100
// https://leetcode.com/problems/continuous-subarray-sum/


/*O(N) solution*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]%k;
        }

        // now it converts to two sum where sum = k or 0

        unordered_map<int,int> mp; // val, index
        vector<int> prefix(nums.size());

        prefix[0] = nums[0];
        mp[prefix[0]] = 0; // need this => very easy to forget

        for(int i=1; i<nums.size(); i++){
            prefix[i] = (prefix[i-1]+nums[i]) % k;

            if(prefix[i] % k == 0) return true;

            // target = prefix[i] or 0
            //if()

            if(mp.find(prefix[i]) != mp.end()){
                int index = mp[prefix[i]];
                if(i-index > 1) return true;
            } else{
                mp[prefix[i]] = i; // I don't want to override prev find values think of TC: [5, 0, 0, 0] K = 3
            }
        }

        return false;
    }
};

// https://leetcode.com/problems/continuous-subarray-sum/description/
// https://leetcode.com/problems/continuous-subarray-sum/solutions/5279413/open-addressing-hash-table-beating-99-79-in-c-77-ms-and-bitset-beating-99-89-67-ms/
