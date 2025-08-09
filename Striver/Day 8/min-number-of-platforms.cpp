class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    static bool compare(const pair<int,int>&a, const pair<int,int>& b)
    {
        return a.first < b.first;
    }
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	// count max overlaps in a single time
    	// sort entry array 
    	// if(dep[i] > arr[j]) count++;
    	
    	//int i,j;
    // 	int i=0,j=0, count=1,maxCount = INT_MIN;
    	
    // 	vector<pair<int,int>> train;
    // 	for(i=0;i<n;i++) train.push_back({arr[i], dep[i]});
    // 	sort(train.begin(), train.end(),compare);
    // 	i=0;
    // 	for(j=1;j<n;j++)
    // 	{
    // 	    if(train[i].second > train[j].first) ++count;
    // 	    else
    // 	    {
    // 	        while(i<j)
    // 	        {
    // 	            if(train[i].second <= train[j].first) ++i;
    // 	            else
    // 	            {
    	                
    // 	                break;
    // 	            }
    // 	        }
    // 	        count = j-i+1;
    // 	    }
    // 	    maxCount = max(count, maxCount);
    // 	}
    	
    // 	return maxCount;
    
    
    
    // another approach
    // we are only interested in a train is coming or leaving not in the dep or arrival of same train
    
        sort(arr,arr+n);
        sort(dep,dep+n);
        int count = 0,i=0,j=0,maxCount=INT_MIN;
        
        while(i<n && j<n)
        {
            if(arr[i] <= dep[j]) ++count,++i;
            else
            {
                // bascally else if(arr[i) > dep[i])
                --count;
                j++;
            }
            
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
    
    
};
// prb: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// sol: https://www.youtube.com/watch?v=dxVcMDI7vyI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=45