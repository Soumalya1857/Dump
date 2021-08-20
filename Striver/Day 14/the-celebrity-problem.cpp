class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // any col that is entirely 1 and the row where it meets with diagonal is all zero
        
         // check all the cols
         for(int col=0;col<n;col++)
         {
             bool potential = true;
             for(int row=0;row<n;row++)
             {
                 if(row != col && M[row][col] != 1)
                 {
                     potential = false;
                     break;
                 }
             }
             
             if(potential)
             {
                 bool celeb = true;
                 for(int i=0;i<n;i++)
                 {
                     if(M[col][i] != 0)
                     {
                            celeb = false;
                            break;
                     }
                 }
                 
                 if(celeb)
                 {
                     return col;
                 }
             }
         }
         
         return -1;
    }
};
// prb: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// though a 2 pointer approach can be possible

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // if A does know B then A not the celeb...B may be 
        // if A doesnot know B...B is not the celeb.. A can be
        
        // maintain a stack
        // pop 2 elements from top and check the condition
        
        stack<int> s;
        for(int i=0;i<n;i++) s.push(i);
        
        while(s.size() != 1)
        {
            int A = s.top(); s.pop();
            int B = s.top(); s.pop();
            
            // does A knows B then A is not he celeb, B can be
            if(M[A][B] == 1) s.push(B);
            // else B is not the celeb, A can be
            else s.push(A);
        }
        
        int celebIdx = s.top();
        
        // check if its really a celeb or not
        for(int i=0; i<n;i++) 
        {
            if(i!=celebIdx && M[i][celebIdx] != 1) return -1;
            if( M[celebIdx][i] == 1) return -1;
            
        }
           
        return celebIdx;
    }
    
    // solution: https://www.youtube.com/watch?v=LtGnA5L6LIk
};