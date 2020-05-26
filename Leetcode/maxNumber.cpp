int maximumSwap(int num) {
        
        int digit = 0,i=0,j=0,maxi = -1,pos;
        int dim = num;
        int a[10];
        for(i=0;i<10;i++) a[i] = -1;
        i = 9;
        while(dim != 0) 
        {
            int temp = dim%10;
            digit++;
            dim/=10;
            a[i--] = temp;
        } 
        for(i= 10-digit; i<9;i++)
        {
            //bool changed = false;
            maxi = -1;
            pos = -1;
            for(j=i+1;j<10;j++)
            {
               if(a[j] >= maxi) maxi = a[j], pos = j;
            }
            if(a[i] < maxi) 
            {
                int temp = a[i];
                a[i] = a[pos];
                a[pos] = temp;
                break;
            }
        }
        
        int ans = 0;
        for(i=0;i<10;i++)
        {
            if(a[i]!=-1)
            {
                ans = ans*10 + a[i];
            }
        }
        return ans;
        
    }



    /***
    https://leetcode.com/problems/maximum-swap/
    ***/