class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        // 1 tuple 8 possibilities
        // can't go and generate all the possiblities

        // sort and 2 pointer maybe
        // any 4 => square, voilla <= nope nope nope 1 2 4 32
        //int ans = 0;
        // sort(nums.begin(), nums.end());

        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         for(int k = j+1; k<nums.size(); k++){
        //             for(int l=k+1; l<nums.size(); l++){
        //                 // float res = sqrt(nums[i] * nums[j] * nums[k] * nums[l]);
        //                 // if(floor(res) == res){
        //                 //     cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << nums[l] << endl;
        //                 //     cout << res << endl;
        //                 //     ans += 8;
        //                 // }

                        
        //             }
        //         }
        //     }
        // }

        int ans = 0;
        
        unordered_map<int, int> map;
        for(int i=0; i<nums.size();i++){
            for(int j=i+1; j<nums.size(); j++){
                map[nums[i] * nums[j]]++;
            }
        }

        for(auto entry : map){
            if(entry.second > 1){
                ans += calcPermutation(entry.second);
            }
        }

        return ans;
    }

    int calcPermutation(int n){
        return 4 * n * (n-1); // 8 * nc2
    }
};

// https://leetcode.com/problems/tuple-with-same-product/submissions/1103523771/