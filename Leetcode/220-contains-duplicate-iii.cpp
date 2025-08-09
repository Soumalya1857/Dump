//TODO: This gives TLE
class Solution {
private:
    int abso(int n){
        return n<0 ? -n : n;
    }
public:
    bool static comparator(const pair<int,int> &a, const pair<int,int> &b){
        if(a.first < b.first){
            return true;
        }else{
            if(a.first == b.first){
                return a.second < b.second;
            }

            return false;
        }
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int,int>> arr;
        for(int i=0; i<nums.size(); i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), comparator);

        int n = arr.size();

        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if(abso(arr[i].first - arr[j].first) <= t){
                    if(abso(arr[i].second - arr[j].second) <= k){
                        return true;
                    }
                }else{
                    break;
                }
            }
        }

        return false;
    }
};
//TODO: This gives TLE

// https://leetcode.com/problems/contains-duplicate-iii/



class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        t=(long)t;          // taking t as long because difference between numbers can be greater than INT_MAX
        multiset<long> s;   //window
        
        for(int i=0;i<n;i++){
            if(i>k){
                s.erase((long)nums[i-k-1]);         // if size of window > k, we are removing elements from window
            }
            
            auto it=s.lower_bound((long)nums[i]-t); // searching for numbers with difference at most t
            long dif=*it-(long)nums[i];             // difference is calculated for further comparisons
            
            if(it!=s.end() && dif<=t){             // if number in window with at most t difference is present 
                return true;
            }
            s.insert(nums[i]); // inserting element in window 
        }
        return false;
    }
};

// https://leetcode.com/problems/contains-duplicate-iii/solutions/1809732/c-sliding-window-multiset-solution-with-comments-easy-understanding/

// https://leetcode.com/problems/contains-duplicate-iii/solutions/61729/java-treeset-26-ms-solution-optimized-with-a-custom-comparator/