//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool compare(const Item &a, const Item &b)
    {
        return (a.value/(a.weight * 1.0) > b.value/(b.weight * 1.0));
    }
 
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, compare);
        //cout << "n: " << n << endl;
        //for(int i=0;i<n;i++) cout << arr[i].value << " " << arr[i].weight << endl;
        double profit = 0;
        for(int i=0;i<n;i++)
        {
            if(W-arr[i].weight >= 0)
            {
                profit += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                if(W > 0)
                {
                    profit += (W / (arr[i].weight*1.0)) * arr[i].value;
                }
                W=0;
            }
           // cout << W << endl;
        }
        
        return profit;
    }
        
};
// prb: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1