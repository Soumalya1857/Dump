
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
        // larger at left
        
        stack<int> s; // will store index in this
        vector<int> ans(n,-1);
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty())
            {
                int top = s.top();
                //cout << top << "  " << price[i] << endl;
                if(price[top] > price[i])
                {
                    ans[i] = i-top;
                    break;
                }
                s.pop();
            }
            if(s.empty()) ans[i] = 1+i;
            s.push(i);
        }
        
       return ans;
    }
};

// prb: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// prev larger element