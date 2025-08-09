class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        if(target % 2 == 0)
        {
            int mid = target/2;
            int freq = 0;
            vector<int>ans;
            for(int i=0;i<nums.size();i++)
            {
                
                if(nums[i] == mid) {freq++; ans.push_back(i);}
                if(freq >=2) return ans;
            }
        }
        
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp.insert({nums[i],i});
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if( (target % 2 == 0) && (nums[i] == target/2))
            {
                // do nothing
            }
            else
            {
                if(mp.find(target-nums[i]) != mp.end())
                {
                    auto itr = mp.find(target-nums[i]);
                    return vector<int>{i,itr->second};
                }
            }
        }
        
        return {};
    }
};

//problem: https://leetcode.com/problems/two-sum/

// better solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int>vjk;
        vector<int> ans;

    for(int i=0;i<nums.size();i++) 
    {
        int comple= target-nums[i];
        
        if ( vjk.find(comple)!=vjk.end())
        {
          ans.push_back(vjk[comple]);
            ans.push_back(i);
            
             break;  
            
            
        }
        else
        {
         vjk.insert(make_pair(nums[i],i))  ; 
        }
         
       
    }
 
   
    return ans;
    }
};

//problem: https://leetcode.com/problems/two-sum/