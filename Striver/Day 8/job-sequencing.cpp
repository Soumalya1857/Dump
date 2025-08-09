struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool compare(const Job &a, const Job &b)
    {
        if(a.dead < b.dead) return true;
        else if(a.dead > b.dead) return false;
        else if(a.profit > b.profit) return true;
        return false;
        
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // sort wrt to deadline
        // if proft same sort ascending order of deadline
        // if deadline is same we are sorting on descending order of profit
        
     
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++)
        { 
            cout << arr[i].id << " " << arr[i].dead << " " << arr[i].profit << endl;
        }
        int deadline = 0, jobCount = 0, profit = 0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i].dead > deadline) {
                
                jobCount++;
                profit += arr[i].profit;
                deadline++;
            }
            else
            {
                while(arr[i+1].dead <= deadline)
                {
                    ++i;
                }
            }
        }
        return vector<int>{jobCount, profit};
    } 
};

// prob: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// different son: https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=47

// queston: can there be a dp solution for this??