class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> store;
        for(int x : nums1){
            store[x] = true;
        }
        vector<int>::iterator it;
        for(it = nums2.begin(); it != nums2.end(); it++){
            if(store[*it]) {
                store[*it] = false;
                continue;
            }
            else {nums2.erase(it); it--;}
        }
        
        return nums2;
    }
};

// good solution under o(n) and 0(1)
/*
function intersections(l1, l2) {
    l1.sort((a, b) => a - b) // assume sorted
    l2.sort((a, b) => a - b) // assume sorted
    const intersections = []
    let l = 0, r = 0;
    while ((l2[l] && l1[r]) !== undefined) {
       const left = l1[r], right = l2[l];
        if (right === left) {
            intersections.push(right)
            while (left === l1[r]) r++;
            while (right === l2[l]) l++;
            continue;
        }
        if (right > left) while (left === l1[r]) r++;
         else while (right === l2[l]) l++;
        
    }
    return intersections;
}
*/

// https://leetcode.com/problems/intersection-of-two-arrays