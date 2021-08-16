class Solution
{
public:

    vector<int> sumOfSet(vector<int>& arr, int pos, int sum, vector<int>&ans)
    {
        if(pos == arr.size()) 
        {
            ans.push_back(sum);
            return ans;
        }
        
        sumOfSet(arr, pos+1, sum+arr[pos], ans);
        sumOfSet(arr, pos+1, sum, ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans, val;
        val = sumOfSet(arr,0,0,ans);
        sort(val.begin(),val.end());
        return val;
        
    }
};
// prb: https://practice.geeksforgeeks.org/problems/subset-sums2234/1
