class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     
        int i,j,k;
        int n = gas.size();
        int start = 0;
        int deficit = 0;
        int tank = 0;
        
        for(i=0;i < n;i++)
        {
//             if(tank + gas[i] < cost[i])
//             {
//                 start++;
//                 deficit += (gas[i] - cost[i]);
//                 tank = 0;
//                 //i = start;
//             }
            
//             else
//             {
//                 tank += (gas[i] - cost[i]);
//             }
            
            
            tank += (gas[i] - cost[i]);
            if(tank < 0)
            {
                deficit += tank;
                tank = 0;
                start = i+1;
            }
            
        }
        cout << "deficit: " << deficit << endl;
        if(deficit + tank >= 0) return start;
        else return -1;
        
    }
};


/*
https://leetcode.com/problems/gas-station/
*/