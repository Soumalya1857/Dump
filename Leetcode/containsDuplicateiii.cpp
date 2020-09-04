class Solution {
public:
    
    static bool compare(pair<int,int>&a, pair<int,int>&b)
    {
        return a.first < b.first;
    }
    
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int,int>> dup;
        int n = nums.size();
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            dup.push_back({nums[i],i});
        }
        
        sort(dup.begin(), dup.end(),compare);   
        
        int i=0,j=1;
        while(j < n)
        {
            if(j == i)
            {
                if(j == n-1) flag = true;
                j++;
            
            }
                
            else
            {
                if(dup[j].first - dup[i].first <= t)
                {
                    if(abs(dup[j].second - dup[i].second) <= k)
                    {
                        //cout << "j: " << dup[j].second << " i: " << dup[i].second << endl;
                        return true;
                    }
                    else
                    {
                        if(abs(dup[j].second - dup[i].second) > k) j++;
                        if(dup[j].first - dup[i].first == t) j++;   
                    }
                }
                else if((dup[j].first - dup[i].first > t))
                {
                    // greater than t
                    i++;
                }
            }
            
        }
        if(flag && j >= n-1 && i < n)
        {
            j = n-1;
            while(i < n)
            {
                if(dup[j].first - dup[i].first <= t)
                {
                    if(abs(dup[j].second - dup[i].second) <= k)
                    {
                        //cout << "j: " << dup[j].second << " i: " << dup[i].second << endl;
                        return true;
                    }
                    else i++;
                }
            }
        }
        
        return false;  
    }
};

/*NOT SUBMITTED*/
/*
https://leetcode.com/problems/contains-duplicate-iii/
https://leetcode.com/problems/contains-duplicate-iii/discuss/824486/Simple-and-Easy-to-understand-C%2B%2B-solution
*/


