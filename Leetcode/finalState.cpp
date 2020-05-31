int nextday(int state)
    {
        int ans = 0;
        for(int i=1;i<=6;i++)
        {
            if(((state>>(i-1))&1) == ((state>>(i+1))&1))
                ans = ans ^ (1<<i);
        }
        return ans;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        map<int,int> seen;
        int state = 0;
        
        for(int i=0;i<8;i++) 
            if(cells[i] > 0) 
                state = state ^ (1<<i);
        
        while(N > 0)
        {
            if(seen.find(state) != seen.end())
            {
                //state seen
                N %=( seen[state] - N );
            }
            seen[state] = N;
            
            if(N>=1)
            {
                N--;
                state = nextday(state);
            }
        }
        
        vector<int>ans(8,0);
        for(int i=0;i<8;i++)
        {
            if(((state >> i) & 1) == 1)
            {
                ans[i] = 1;
            }
        }
        return ans;
        
    }


    /****
    https://leetcode.com/problems/prison-cells-after-n-days/
    
    ***/