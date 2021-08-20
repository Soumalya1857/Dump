class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        
        int size = str.size(), ans=0;
        bool neg = false;
        for(int i=0;i<size;i++)
        {
            if(i==0 && str[i] == '-') {neg = true; continue;}
            if(str[i] >='0' && str[i] <='9')
            {
                ans = ans*10 + int(str[i])-'0';
            }
            else return -1;
        }
        
        return neg? -ans : ans;
    }
};