class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // can be done by range max queries
        // balanced heap seems to be a nice option
        
        // so usage of a heap can be done by sets
        // https://stackoverflow.com/questions/19467485/how-to-remove-element-not-at-top-from-priority-queue
        
        
        multiset<int> s;
        for(int i=0;i<k;i++) s.insert(nums[i]);
        
        vector<int>ans;
        ans.push_back(*s.rbegin());
        // now sliding window start
        for(int i=k; i<nums.size();i++)
        {
            // insert in set
            s.insert(nums[i]);
            
            // delete last elemet of window
            auto it = s.find(nums[i-k]);
            s.erase(it);
            
            ans.push_back(*s.rbegin());
        }
        
        
        return ans;
    }
};
// usage of set as min or max heap


// deque solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // deque approach
        // we want to maintain the numbers in a decreasing fashion inside the deque
        
        deque<int> dq; // will store the index only
        vector<int> ans;
        
        // for(int i=0;i<k;i++) dq.push_back(nums[i]);
        
        for(int i=0;i<nums.size();i++)
        {
            // check if my element in the queue is out of bound or not
            if(!dq.empty() && dq.front() <= i-k) // out of bound
            {
                dq.pop_front();
            }
            
            // check if my current element is larger than any present deque element or not
            // if yes than remove those elements
            
            while(!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            if(i >= k-1) ans.push_back(nums[dq.front()]); // max element always at the front
        }
        
        return ans;
    }
};

// prb: https://leetcode.com/problems/sliding-window-maximum/
// soln: https://www.youtube.com/watch?v=CZQGRp93K4k&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=85