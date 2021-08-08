class Solution {
public:
    
    void swap(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2){
        
        int temp = matrix[x1][y1];
        matrix[x1][y1] = matrix[x2][y2];
        matrix[x2][y2] = temp;
    }
    
    void reverse(vector<int>& row, int i, int j)
    {
        while(i < j)
        {
            int temp = row[i];
            row[i] = row[j];
            row[j] = temp;
            i++; j--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        // swap mirrors wrt the diagonal
        // reverse the rows
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=i+1;j<c;j++)
            {
                swap(matrix, i,j , j,i);
            }
        }
         
      // reverse the rows
        for(int i=0;i<r;i++)
        {
            reverse(matrix[i],0,c-1);
        }
    }
};

// ques: https://leetcode.com/problems/rotate-image/submissions/